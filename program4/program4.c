/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Manages Customer Accounts Receivable      */
/*                          Database                                  */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 20, 2015                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge  all of the lines  in this C program  are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/*                        my CS227 instructor.                        */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program ask for each customer accounts receivable (customer's */
/* last name, amount owed, and their priority number).  This program  */
/* then sorts the customer alphabetically and cleans the customer's   */
/* name and prints the customer accounts receivable alphabetically.   */  
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit                                           */
#include <string.h> /* memcpy                                         */
#include <ctype.h>  /* tolower, toupper, toalpha                      */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define DB_ALLOC_ERROR  1        /* Error in allocating the data      */
#define END_OF_STRING   '\0'     /* Last value in a string            */
#define MAX_CUSTOMERS   100      /* Maximum number of customers       */
#define MAX_NAME_LENGTH 20       /* Maximum letters in a name         */
#define MIN_CUSTOMERS   2        /* Minimum number of customers       */
#define NEW_LINE        '\n'     /* New line value                    */
#define PROGRAM_NUMBER  4        /* Teacher assigned program number   */
#define PROGRAMMER_NAME "Norris" /* Programmer's last name            */
#define QUIT            0        /* Program exit value                */

/**********************************************************************/
/*                          Program Structure                         */
/**********************************************************************/
/* Database of customer accounts receivable records                   */
struct customer
{
   char  last_name[MAX_NAME_LENGTH + 1]; /* Last name of the customer */
   float amount_owed;                    /* The amount owed           */
   int   priority;                       /* Customer priority number  */
};

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Prints the program's heading                                    */
void print_instructions();
   /* Prints the program's instructions                               */
int get_number_customers();
   /* Get number of customers                                         */
void get_customers(struct customer *p_customer_start, 
                                               int number_of_customers);
   /* Get the customer data                                           */
void clean_names(struct customer *p_customer_start, 
                                               int number_of_customers);
   /* Remove non-letters and upper case the first letter of names     */
void sort_customers(struct customer *p_customer_start, 
                                               int number_of_customers);
   /* Sort the names in alphabetical order by last name               */
void print_customers(struct customer *p_customer_start, 
                                               int number_of_customers);
   /* Print the data of the customers                                 */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   struct customer *p_customer;         /* Points to every customer   */
   int             number_of_customers; /* Number of customers        */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing customer accounts receivable until the user     */   
   /* quits */
   while(print_instructions(), 
        (number_of_customers = get_number_customers()) != QUIT)
   {
      /* Allocate customer data and abort if unavailable              */
      if((p_customer = (struct customer *)malloc(sizeof(*p_customer)
        * number_of_customers)) == NULL)
      {
         printf("\nError number %d has occurred in main.", 
                                                        DB_ALLOC_ERROR); 
         printf("\nCould not allocate customer information.");
         printf("\nThe program is aborting.");
         exit(DB_ALLOC_ERROR);
      }
      
      /* Get the customer data, clean name, sort data, and print it   */
      get_customers  (p_customer, number_of_customers);
      clean_names    (p_customer, number_of_customers);
      sort_customers (p_customer, number_of_customers);
      print_customers(p_customer, number_of_customers);

      /* Indicate the end of database processing                      */
      printf("\n\n******* End of Customer Database Processing *******");
      printf("\n");

      /* Release the memory in the customer database                  */
      free(p_customer);
   }   

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for processing numbers.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Print the Program Heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\n");
   return;
}

/**********************************************************************/
/*                      Print the Instructions                        */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program allows you to input customers which owe");
   printf("\nyou money (your accounts receivable), and manage these");
   printf("\naccounts in a database.  You will enter the following:");
   printf("\n   Customer last name (1-%d characters)", MAX_NAME_LENGTH);
   printf("\n   Amount the customer owes (to the exact cent)");
   printf("\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf("\nFrom %d to %d customers may be processed.", MIN_CUSTOMERS, 
      MAX_CUSTOMERS);
   printf("\n");
   printf("\nGet the customers for the database");
   printf("\n--------------------------------------------------");
   return;
}

/**********************************************************************/
/*                      Get number of customers                       */
/**********************************************************************/
int get_number_customers()
{
   int number_of_customers; /* Number of customers                    */

   do
   {
      printf("\nHow many customers do you have (%d to %d, %d=quit): ",
         MIN_CUSTOMERS, MAX_CUSTOMERS, QUIT);
      scanf ("%d", &number_of_customers);
   }
   while((number_of_customers < MIN_CUSTOMERS || 
        number_of_customers > MAX_CUSTOMERS) && 
        number_of_customers != QUIT);

   return number_of_customers;
}

/**********************************************************************/
/*            Get the customer accounts receivable record             */
/**********************************************************************/
void get_customers(struct customer *p_customer_start, 
                                                int number_of_customers)
{
   struct customer *p_customer;  /* Points to every customer          */
   char            *p_last_name; /* Points to every character in the  */
                                 /* last name                         */

   for(p_customer = p_customer_start; (p_customer - p_customer_start) 
      < number_of_customers; p_customer++)
   {
      p_last_name = p_customer->last_name;
      printf("\nCustomer number %d:", 
         (int)((p_customer - p_customer_start) + 1));
      printf("\n   Enter the customer's last name: ");
      getchar();
      do
      {
         *p_last_name++ = getchar();         
      }
      while(*(p_last_name - 1) != NEW_LINE);
      *(p_last_name - 1) = END_OF_STRING;

      printf("   Enter the amount owed: ");
      scanf ("%f", &p_customer->amount_owed);

      do
      {
         printf("   Enter the customer's priority (1-3): ");
         scanf ("%d", &p_customer->priority);
      }
      while(p_customer->priority < 1 || p_customer->priority > 3);
   }
   return;
}

/**********************************************************************/
/*                    Clean the customer's name                       */
/**********************************************************************/
void clean_names(struct customer *p_customer_start, 
                                                int number_of_customers)
{
   struct customer *p_customer; /* Points to every customer           */
   char            *p_fast,     /* Points to every char in word       */
                   *p_slow;     /* Receives all valid characters      */

   for(p_customer = p_customer_start; (p_customer - p_customer_start) 
      < number_of_customers; p_customer++)
   {
      p_fast = p_customer->last_name;
      p_slow = p_customer->last_name;

      while(*p_fast != END_OF_STRING)
      {
         if(isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++; 
      }
      *p_slow = END_OF_STRING;
      *p_customer->last_name = toupper(*p_customer->last_name);
   }
   return;
}

/**********************************************************************/
/*          Sort the customer accounts receivable record              */
/**********************************************************************/
void sort_customers(struct customer *p_customer, 
                                                int number_of_customers)
{
   struct customer *p_outer,      /* Points to the first name in      */
                                  /* the name                         */ 
                   *p_inner,      /* Points to the second name        */  
                                  /* in the name                      */
                   customer_temp; /* Temporary customer               */

   for(p_outer = p_customer; (p_outer - p_customer)
      < number_of_customers; p_outer++)
      for(p_inner = (p_outer + 1); (p_inner - p_customer) 
         < number_of_customers; p_inner++)
         if(strcmp(p_outer->last_name, p_inner->last_name) > 0)
         {
            customer_temp = *p_outer;
            *p_outer      = *p_inner;
            *p_inner      = customer_temp;
         }
   return;
}

/**********************************************************************/
/*           Print the customer accounts receivable record            */
/**********************************************************************/
void print_customers(struct customer *p_customer_start, 
                                                int number_of_customers)
{
   struct customer *p_customer; /* Points to every customer           */

   printf("\n  Here is the accounts receivable customer database");
   printf("\n=====================================================");
   printf("\n   Customer Name         Amount        Priority");
   printf("\n--------------------    ---------    -------------");

   for(p_customer = p_customer_start; (p_customer - p_customer_start) 
      < number_of_customers; p_customer++)
   {
      printf("\n%20s"     , p_customer->last_name);
      printf("    $%8.2f" , p_customer->amount_owed);
      printf("     %d"    , p_customer->priority);

      switch(p_customer->priority)
      {
         case 1:
            printf("(VIP)");
            break;
         case 2:
            printf("(Important)");
            break;
         case 3:
            printf("(Regular)");
            break;
      }    
   }
   return;
}

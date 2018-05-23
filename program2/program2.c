/**********************************************************************/
/*                                                                    */
/* Program Name: program2 - Miscellaneous Operations on Two Whole     */
/*                          Numbers                                   */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Data Written: September 26, 2015                                   */
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
/* This program asks the user for a choice: to add two whole numbers, */
/* raise the first number to the power of the second, sum all numbers */
/* between two whole numbers, put two whole numbers in ascending      */
/* order, or quit.  After the user select the one he wants; the       */
/* program then asks the user for two whole numbers or quits if quit  */
/* is selected, then prints out the answer.                           */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit                                           */
#include <math.h>   /* pow                                            */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"  /* PCC assigned course number      */
#define MAX_MENU_CHOICE   5        /* End of menu choice              */
#define MENU_CHOICE_ERROR 1        /* Error in menu choice            */
#define MIN_MENU_CHOICE   1        /* Start of menu choice            */
#define PROGRAM_NUMBER    2        /* Teacher assigned program number */
#define PROGRAMMER_NAME   "Norris" /* Programmer last name            */
#define QUIT              5        /* Quits program                   */ 

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_menu();
   /* Print the menu                                                  */
int get_menu_choice();
   /* Gets the user's menu choice                                     */
void get_two_whole_numbers(int *p_first_number,int *p_second_number);
   /* Gets the user's two whole numbers                               */
int get_sum(int first_number, int second_number);
   /* Gets the sum of the two numbers                                 */
float get_raise_number(int first_number, int second_number);
   /* Raises the first number to the power of the second              */
int get_sum_range(int first_number, int second_number);
   /* Gets the sum of all the between two whole numbers               */
void swap(int *p_first_number,int *p_second_number);
   /* Puts two whole numbers in ascending order                       */ 

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int menu_choice,   /* Which menu number the user wants             */
       first_number,  /* First number that is used for the operation  */
       second_number; /* Second number that is used for the operation */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing whole number pairs until user says to quit      */
   while(print_menu(), (menu_choice = get_menu_choice()) != QUIT)
   {
      /* Get the two whole numbers                                    */
      get_two_whole_numbers(&first_number, &second_number);

      /* Process menu choice                                          */
      switch(menu_choice)
      {
         case 1:
            /* Adds the numbers and prints the results                */
            printf("The sum of %d and %d is %d", first_number, 
                   second_number, get_sum(first_number, second_number));
            break;
         case 2:
            /* Raise the 1st number to the power of the 2nd number    */
            /* and prints results                                     */
            printf("%d raised to the power of %d = %1.6e", first_number,
               second_number, get_raise_number
                                          (first_number,second_number));
            break;
         case 3:
            /* Adds all the numbers between the two whole numbers     */
            /* and prints results                                     */
            if (first_number > second_number)
               swap(&first_number, &second_number);
            
            printf("The sum of the numbers between %d and %d ",
                                           first_number, second_number);
            printf("(inclusive) is %d",
                            get_sum_range(first_number, second_number));
            break;
         case 4:
            /* Swaps the two number if they are out of order and      */
            /* print results                                          */
            if (first_number > second_number)
            {
               printf("%d and %d properly ordered are: ", first_number,
                                                         second_number);
               swap(&first_number, &second_number);
               printf("%d and %d", first_number, second_number);
            }
            else
               printf("%d and %d are already in order", first_number,
                                                         second_number);
            break;
         default:
            /* Display error if impossible menu choice occurs         */
            printf("Error #%d occured in get_menu_choice().",
               MENU_CHOICE_ERROR);
            printf("Reason: Impossible menu choice.");
            printf("The program is aborting.");
            printf("\n\n\n\n\n\n");
            exit(MENU_CHOICE_ERROR);
            break;
      }
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for processing numbers.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");

   return 0;
}

/**********************************************************************/
/*                      Print the program heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\n   Miscellaneous operations on your two whole numbers");
   return;
}

/**********************************************************************/
/*                             Print Menu                             */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake a selection from the following menu:");
   printf("\n-----------------------------------------");
   printf("\n    1 - Add two whole numbers");
   printf("\n    2 - Raise the 1st number to the power of the 2nd");
   printf("\n    3 - Sum all numbers between two numbers");
   printf("\n    4 - Put two whole numbers into ascending order");
   printf("\n    5 - Quit");
   return;
}

/**********************************************************************/
/*                           Get Menu Choice                          */
/**********************************************************************/
int get_menu_choice()
{
   int menu_choice;

   do 
   {
      printf("\nEnter your menu selection (1-5): ");
      scanf (" %d", &menu_choice);
   }
   while((menu_choice > MAX_MENU_CHOICE) || 
                                       (menu_choice < MIN_MENU_CHOICE));
   
   return(menu_choice); 
}

/**********************************************************************/
/*                         Get the Whole Numbers                      */
/**********************************************************************/
void get_two_whole_numbers(int *p_first_number,int *p_second_number)
{
   printf("\nType in any two whole numbers now:");
   printf("\n    What is your first number: ");
   scanf (" %d", p_first_number);

   printf("    Give me your second number: ");
   scanf (" %d", p_second_number);

   return;
}

/**********************************************************************/
/*                               Get Sum                              */
/**********************************************************************/
int get_sum(int first_number, int second_number)
{
   return(first_number + second_number);
}

/**********************************************************************/
/*                          Get Raise Number                          */
/**********************************************************************/
float get_raise_number(int first_number, int second_number)
{
   return(pow((double) first_number,(double) second_number));
}

/**********************************************************************/
/*                            Get Sum Range                           */
/**********************************************************************/
int get_sum_range(int first_number, int second_number)
{
    int counter,
        sum = 0;

   for (counter = first_number; counter <= second_number; counter++)
      sum += counter;
   
   return(sum);
}

/**********************************************************************/
/*                                 Swap                               */
/**********************************************************************/
void swap(int *p_first_number,int *p_second_number)
{
   if (p_first_number > p_second_number)
   {
      int temp_number  = *p_first_number;
      *p_first_number  = *p_second_number;
      *p_second_number = temp_number;
   }

   return; 
}

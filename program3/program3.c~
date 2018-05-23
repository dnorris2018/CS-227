/**********************************************************************/
/*                                                                    */
/* Program Name: program3 - Processes Experimental Scientific Data    */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 12, 2015                                     */
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
/* This program sorts an array of whole numbers and puts them in      */
/* descending order.  Then prints out the sorted array and the sum of */
/* all the whole numbers.                                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* malloc, free                                   */
#include <string.h> /* strings                                        */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER         "CS227"  
   /* PCC assigned course number                                      */
#define DATA_ALLOCATION_ERROR 1
   /* Error in allocating the data                                    */
#define MAX_QUANTITY          100
   /* Maximum quantity                                                */
#define MIN_QUANTITY          2
   /* Minimum quantity                                                */
#define PROGRAM_NUMBER        3        
   /* Teacher assigned program number                                 */
#define PROGRAMMER_NAME       "Norris" 
   /* Programmer's last name                                          */
#define QUIT                  0
   /* Exit value                                                      */
#define SORT_ALLOCATION_ERROR 2
   /* Error in sorting the data                                       */

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Prints the program's heading                                    */
void print_instructions();
   /* Prints the program's instructions                               */
int get_quantity();
   /* Gets the array size                                             */
void get_data(float *p_data_start, int quantity);
   /* Gets the numbers that are in the array                          */
void sort_data(float *p_data_start, int quantity);
   /* Puts the data in descending order                               */
void print_data(float *p_data_start, int quantity);
   /* Prints data and notes duplicate                                 */
float sum_data(float *p_data, int quantity);
   /* Sums the data that was entered                                  */
void print_total(float sum);
   /* Prints the total of the data                                    */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int   quantity; /* Size of the array of data                       */
   float *p_data;  /* Points to every whole number                    */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing whole number pairs until user says to quit      */
   while(print_instructions(), (quantity = get_quantity()) != QUIT)
   {
      /* Allocate memory for data and abort if unavailable            */
      if((p_data = (float *)malloc(sizeof(*p_data) * quantity)) == NULL)
      {
         printf("\nError %d occurred in main", DATA_ALLOCATION_ERROR);
         printf("\nUnable to allocate memory for sorted data");
         printf("\nThis program is aborting");
         exit(SORT_ALLOCATION_ERROR);
      }

      /* Gets, sorts, prints the data and sums the data and           */
      /* prints total                                                 */
      get_data   (p_data, quantity);
      sort_data  (p_data, quantity);
      print_data (p_data, quantity);
      print_total(sum_data(p_data, quantity));

      /* Release the memory allocated to the data array               */
      free(p_data);
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
   printf("\n");
   printf("\nThis program processes experimental scientific data");
   printf("\n---------------------------------------------------");
   printf("\n");
   return;
}

/**********************************************************************/
/*                          Get the Quantity                          */
/**********************************************************************/
int get_quantity()
{
   int quantity; /* Size of the array of data                         */

   do 
   {
      printf("How many data values are there (%d to ",MIN_QUANTITY);
      printf("%d, %d=quit): ", MAX_QUANTITY, QUIT);
      scanf (" %d", &quantity);
   }
   while(((quantity < MIN_QUANTITY) || (quantity > MAX_QUANTITY)) && 
      (quantity != QUIT));
   
   return quantity; 
}

/**********************************************************************/
/*                           Get the Data                             */
/**********************************************************************/
void get_data(float *p_data_start, int quantity)
{
	float *p_data; /* Points to every whole number                     */
	
   for(p_data = p_data_start;(p_data - p_data_start) < quantity; 
      p_data++)
	{
		printf("    Enter data value %d: ", 
         (int)(p_data - p_data_start + 1));
		scanf (" %f", p_data);

      if(*p_data < 0)
      {
         printf("        Negative %.2f converted to ", *p_data);
         *p_data = -(*p_data);
         printf("positive %.2f", *p_data);
         printf("\n");
      }
	}
   return;
}

/**********************************************************************/
/*                           Sort the Data                            */
/**********************************************************************/
void sort_data(float *p_data_start, int quantity)
{
   float *p_sort,       /* Points to all sorted whole numbers         */
         *p_sort_start, /* Points to the start of the sort array      */
         *p_data,       /* Points to every whole number               */
         *p_biggest;    /* Points to the biggest number in the array  */

   /* Allocate memory for sorted data and abort if unavailable        */
   if((p_sort_start = (float *)malloc(sizeof(*p_sort_start) * quantity)) 
      == NULL)
   {
      printf("\nError %d occurred in sort_data", SORT_ALLOCATION_ERROR);
      printf("\nUnable to allocate memory for sorted data");
      printf("\nThis program is aborting");
      exit(SORT_ALLOCATION_ERROR);
   }
   
   /* Loop sorts data until end of array */
   for(p_sort = p_sort_start; (p_sort - p_sort_start) < quantity; 
      p_sort++)
   {
      *p_sort = 0.0f;

      for(p_data = p_data_start; (p_data - p_data_start) < quantity;
         p_data++)
      {
         if(*p_sort < *p_data)
         {
            p_biggest = p_data;
            *p_sort   = *p_biggest;
         }
      }

      *p_biggest = 0.0f;
   }

   /* Copys the sort array into the data array                        */
   memcpy(p_data_start, p_sort_start, sizeof(*p_sort_start) * quantity);

   /* Release the memory allocated to the sort array                  */
   free(p_sort_start);       
   return;
}

/**********************************************************************/
/*                           Print the Data                           */
/**********************************************************************/
void print_data(float *p_data_start, int quantity)
{
   float *p_data; /* Points to every whole number                     */

   printf("\nThe data in descending order (with duplicates noted):");
   printf("\n-----------------------------------------------------");

   for(p_data = p_data_start;(p_data - p_data_start) < quantity; 
      p_data++)
   {
      if(*p_data == *(p_data -1))
         printf("\n                 %9.2f(duplicates)", *p_data);
      else
         printf("\n                 %9.2f", *p_data);
   }
   return;
}

/**********************************************************************/
/*                           Sum the Data                             */
/**********************************************************************/
float sum_data(float *p_data_start, int quantity)
{
   float *p_data,    /* Points to every whole number 						 */
         sum = 0.0f; /* The sum of the whole numbers                  */

   for(p_data = p_data_start; (p_data - p_data_start) < quantity; 
      p_data++)
      sum += *p_data;

   return sum;
}

/**********************************************************************/
/*                          Print the Total                           */
/**********************************************************************/
void print_total(float sum)
{
   printf("\n                 ---------");
   printf("\n                 %9.2f total", sum);
   return;
}

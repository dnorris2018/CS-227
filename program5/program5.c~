/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursive Sums All Even Number            */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 30, 2015                                     */
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
/* This program recursively add all the even numbers in a range       */
/* (inclusively).  Also print the recursion information.              */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <ctype.h>  /* tolower, toupper, toalpha                      */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define MAX_VALUE       5000     /* Maximum value                     */
#define MIN_VALUE       -5000    /* Minimum value                     */
#define PROGRAM_NUMBER  5        /* Teacher assigned program number   */
#define PROGRAMMER_NAME "Norris" /* Programmer's last name            */

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Print the program's heading                                     */
void print_instructions();
   /* Print the program's instructions                                */
char get_response();
   /* Get the response to do the calculation								    */
void get_range(int *p_start_range, int *p_end_range);
   /* Get the range that is to be calculated                          */
void swap_range(int *p_start_range, int *p_end_range);
   /* Swap the order of the range if it is out of order 					 */
int is_even(int start_range);
   /* Check if the number is even												 */
int sum_even(int start_range, int end_range);
   /* Calculate recursively all even numbers in a range               */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
	int start_range, /* First number in the range                      */
		 end_range,   /* Second number in the range                     */
       sum;         /*                      */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Loop processing recursive summing even numbers until the user   */
   /* enter "n"                                                       */   
   while(get_response() == 'y')
   {
      /* Get the range                                                */
      get_range(&start_range, &end_range);

      /* Print the recursive sum of even numbers                      */
      printf("\nProcessing the range %d to %d:", start_range, 
                                                             end_range);
      if(start_range > end_range)
         swap_range(&start_range, &end_range);
      sum = sum_even(start_range, end_range);
      printf("\nThe sum of all even numbers in the range %d to %d is: ",
         start_range, end_range);
      printf("%d", sum);
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for \"even summing\".  Have a nice day! ;-)");
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
   return;
}

/**********************************************************************/
/*                      Print the Instructions                        */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two number inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed.  Information");
   printf("\nabout the recursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n                 may be observed"                  );
   return;
}

/**********************************************************************/
/*                          Get the Response                          */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Store a 'y' or 'n' character                  */

   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf ("%1s", &response[0]);
      response[0] = tolower(response[0]);      
   }   
   while(response[0] != 'y' && response[0] != 'n');
   return response[0]; 
}

/**********************************************************************/
/*                          Get the Range                             */
/**********************************************************************/
void get_range(int *p_start_range, int *p_end_range)
{
   printf("\n");		 
	do
	{
		printf("Enter in the first number (from %d to %d): ", MIN_VALUE, 
																				 MAX_VALUE);
		scanf ("%d", p_start_range);
	}
	while(*p_start_range > MAX_VALUE || 
         *p_start_range < MIN_VALUE);

   printf("\n");																		 
	do
	{
		printf("Enter in the last number (from %d to %d): ", 
         MIN_VALUE, MAX_VALUE);
		scanf ("%d", p_end_range);
	}
	while(*p_end_range > MAX_VALUE || *p_end_range < MIN_VALUE);
   return;
}

/**********************************************************************/
/*                       Swap the Range Number                        */
/**********************************************************************/
void swap_range(int *p_start_range, int *p_end_range)
{
	*p_start_range += *p_end_range;
	*p_end_range    = *p_start_range - *p_end_range;
	*p_start_range  = *p_start_range - *p_end_range;  
   return;
}

/**********************************************************************/
/*                       Check for Even Number                        */
/**********************************************************************/
int is_even(int start_range)
{
   return start_range % 2 == 0;
}

/**********************************************************************/
/*                             Recursive                              */
/**********************************************************************/
int sum_even(int start_range, int end_range)
{
   int range_sum; /* Sum of even numbers in a number range            */
   
   printf("\n    Entering sum function for range %d to %d", start_range,
                                                             end_range);

   if(start_range > end_range)
      range_sum = 0;
   else
   {
      if(is_even(start_range))
      {
         printf("\n        Adding: %d", start_range);
         range_sum = start_range + sum_even(start_range + 1, end_range);
      }
      else
      {
         printf("\n        Skipping: %d", start_range);
         range_sum = sum_even(start_range + 1, end_range);
      }
   }
   printf("\n    Exiting sum function for range %d to %d ", 
      start_range, end_range);
   printf("with result: %d", range_sum);
   return range_sum;
}

/**********************************************************************/
/*                                                                    */
/* Program Name: program1 - Range Sum                                 */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Data Written: September 11, 2015                                   */
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
/* This program asks the user for a minimum number and a maximum      */
/* number and then it sum all the numbers between them.               */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf, scanf                                   */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define PROGRAM_NUMBER 1              /* Teacher assigned program num */
#define USER_NAME      "David Norris" /* Programmer name              */
#define COURSE_NUMBER  "CS227"        /* PCC assigned course number   */

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
int get_range(int *p_minimum, int *p_maximum);
   /* Get the minimum number and maximum number                       */
void print_sum(int minimum, int maximum);
   /* Calculate the sum of all the numbers between the minimum and    */
   /* maximum                                                         */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int maximum, /* The end of the user's range                        */
       minimum; /* The beginning of the user's range                  */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Get the minimum and maximum number                              */
   get_range(&minimum, &maximum);

   /* Calculate the sum                                               */
   print_sum(minimum, maximum);

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThanks for using this program.  Have a nice day! ;-)");
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
   printf("\n                Programmer: %s",        USER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\n\nI'll sum whole numbers in a number range (inclusively)");
   printf(".");
   printf("\n-------------------------------------------------------"); 
   return;
}

/**********************************************************************/
/*                   Get for the Minimum and Maximum                  */
/**********************************************************************/
int get_range(int *p_minimum, int *p_maximum)
{
   printf("\nEnter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number: ");
   scanf ("%d", p_minimum);

   printf("    Give me your large number: ");
   scanf ("%d", p_maximum);

   return (*p_maximum);
}

/**********************************************************************/
/*                   Calculate the Sum of the Range                   */
/**********************************************************************/
void print_sum(int minimum, int maximum)
{
   int counter,
       sum = 0;

   for (counter = minimum; counter <= maximum; counter++)
   {
      sum = sum + counter;
   }

   printf("\nThe sum of all numbers between %d and ", minimum);
   printf("%d (inclusively) is %d", maximum, sum);

   return;
}

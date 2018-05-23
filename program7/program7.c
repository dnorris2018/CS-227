/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Various Search Algorithms                 */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 17, 2015                                    */
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
/* This program demonstrates various search algorithms by letting the */
/* user enter a whole number to search for it in an ordered array     */
/* using the ordered sequential, probability, and binary searchs.     */
/* Each process is printed out so the user can compare each search    */
/* algorithm.                                                         */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define DATA_SIZE       15       /* Size of data in the arrays        */
#define MAX_INDEX       14       /* Maximum number of indexs          */
#define PROGRAM_NUMBER  7        /* Teacher assigned program number   */
#define PROGRAMMER_NAME "Norris" /* Programmer's last name            */
#define QUIT            0        /* Quits the program                 */

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Print the program's heading                                     */
void print_instructions();
   /* Prints the program's instructions                               */
void fill_data(int array_data[], int max_index);
   /* Fills data into the three different arrays                      */
void show_data(int array_data[], int max_index, int search_target);
   /* Prints array index, array data, user target                     */
void search_result(char search_outcome, int target_index);
   /* Prints where target is found and search outcome                 */
int ordered_sequential_search(int seq_data[],    int max_index, 
                              int search_target, int *p_target_index);
   /* Uses the ordered sequential search to find the user's target    */
int probability_search(int prb_data[], int max_index, int search_target, 
                                                   int *p_target_index);
   /* Uses the probability search to find the user's target           */
int binary_search(int bin_data[], int max_index, int search_target, 
                                                   int *p_target_index);
   /* Uses the binary search to find the user's target                */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int bin_data[DATA_SIZE], /* Binary search data                     */
       prb_data[DATA_SIZE], /* Probability search data                */
       search_target,       /* Number being searched for              */
       seq_data[DATA_SIZE], /* Ordered sequential search data         */
       target_index;        /* Index of the target                    */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Fill data into the three different arrays                       */
   fill_data(seq_data, MAX_INDEX);
   fill_data(prb_data, MAX_INDEX);
   fill_data(bin_data, MAX_INDEX);

   /* Loop processing the search algorithms until user choses to quit */   
   while(printf("\n\n\nEnter an integer search target (%d to quit): ", 
      QUIT), scanf("%d", &search_target), search_target != QUIT)
   {
      /* Uses the ordered sequential search to find the user's target */
      printf("\n\nOrdered Sequential Search:");
      show_data(seq_data, MAX_INDEX, search_target);
      if(ordered_sequential_search(seq_data, MAX_INDEX, search_target, 
                                                         &target_index))
         search_result('S', target_index);
      else
         search_result('U', target_index);

      /* Uses the probability search to find the user's target        */
      printf("\n\nProbability Search:");
      show_data(prb_data, MAX_INDEX, search_target);
      if(probability_search(prb_data, MAX_INDEX, search_target, 
                                                         &target_index))
         search_result('S', target_index);
      else
         search_result('U', target_index);

      /* Uses the binary search to find the user's target             */
      printf("\n\nBinary Search:");
      show_data(bin_data, MAX_INDEX, search_target);
      if(binary_search(bin_data, MAX_INDEX, search_target, 
                                                         &target_index))
         search_result('S', target_index);
      else
         search_result('U', target_index);   
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for searching.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Print the Program Heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        PROGRAMMER_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                      Print the Instructions                        */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program demonstrates various search algorithms.");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequential Search");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
	printf("\nof the search algorithms can be compared.");
   return;
}

/**********************************************************************/
/*               Fill the Array with Order Whole Numbers              */
/**********************************************************************/
void fill_data(int array_data[], int max_index)
{
   int array_index; /* Index of every whole number                    */

   for(array_index = 0; array_index <= max_index; array_index++)
      array_data[array_index] = (array_index * 5) + 10;

   return;
}

/**********************************************************************/
/*                  Print the Data and Search Target                  */
/**********************************************************************/
void show_data(int array_data[], int max_index, int search_target)
{
   int array_index; /* Index of every whole number                          */

   printf("\n   Array Index: ");
   for(array_index = 0; array_index <= max_index; array_index++)
      printf("[%2d]", array_index);
   
   printf("\n    Array Data:");
   for(array_index = 0; array_index <= max_index; array_index++)
      printf("  %2d", array_data[array_index]);
  
   printf("\n   User Target:  %2d",  search_target);
   return;
}

/**********************************************************************/
/*                           Search Result                            */
/**********************************************************************/
void search_result(char search_outcome, int target_index)
{
   if(search_outcome == 'S')
   {
      printf("\nSearch Outcome: Successful - target found at index ");
      printf("[%2d]", target_index);
   }
   else
      if(search_outcome == 'U')
         printf("\nSearch Outcome: Unsuccessful - target not found ");
      else
         printf("\nUndetermined");
   return;
}

/**********************************************************************/
/*                     Ordered Sequential Search                      */
/**********************************************************************/
int ordered_sequential_search(int seq_data[],    int max_index, 
                              int search_target, int *p_target_index)
{
   int array_index = 0; /* Index of every searched whole number       */

   printf("\n   Search Path: ");

   if(search_target <= seq_data[max_index])
   {
      while(search_target > seq_data[array_index])
      {
         printf("[%2d]", array_index);
         array_index += 1;
      }
      printf("[%2d]", array_index);
   }
   else
      printf("[%2d]", max_index);

   *p_target_index = array_index;

   return(search_target == seq_data[*p_target_index]);
}

/**********************************************************************/
/*                        Probability Search                          */
/**********************************************************************/
int probability_search(int prb_data[], int max_index, int search_target, 
                                                    int *p_target_index)
{
   int array_index = 0, /* Index of every searched whole number       */
       temp_data;       /* Temporary data for the swap                */

   printf("\n   Search Path: ");

   while(search_target != prb_data[array_index] && 
      array_index < max_index)
   {
      printf("[%2d]", array_index);
      array_index++;
   }
   
   printf("[%2d]", array_index);

   if(search_target == prb_data[array_index] && array_index != 0)
   {
      temp_data                 = prb_data[array_index];
      prb_data[array_index]     = prb_data[array_index - 1];
      prb_data[array_index - 1] = temp_data;
      *p_target_index = array_index - 1;
   }

   return(search_target == prb_data[*p_target_index]);
}

/**********************************************************************/
/*                           Binary Search                            */
/**********************************************************************/
int binary_search(int bin_data[], int max_index, int search_target, 
                                                    int *p_target_index)
{
   int beginning_index = 0,         /* The beginning of search        */
       end_index       = max_index, /* The end of search              */
       middle_index;                /* The middle of serch            */

   printf("\n   Search Path: ");

   while(beginning_index <= end_index)
   {
      middle_index = (beginning_index + end_index) / 2;
      printf("[%2d]", middle_index);
      
      if(search_target > bin_data[middle_index])
         beginning_index = middle_index + 1;
      
      else
         if(search_target < bin_data[middle_index])
            end_index = middle_index - 1;

         else
            beginning_index = end_index + 1;
   }
   
   *p_target_index = middle_index;
   return(search_target == bin_data[*p_target_index]);
}

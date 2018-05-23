/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - Link List of Student IDs                  */
/* Author:       David Norris                                         */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 30, 2015                                    */
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
/* This program maintains a list of student IDs.  After entering      */
/* all the IDs, the prpgram will print the list the way the user      */
/* enter it, then it will it and print the sorted list.   Also it     */
/* will remove duplicates and then print the list again; it also      */
/* keeps count of the student IDs and print it with each time it      */
/* prints thelist.                                                    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* malloc, free                                   */
#include <ctype.h>  /* tolower                                        */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"    /* PCC assigned course number    */
#define HEADER_ALLOC_ERR  1          /* Cannot allocate header data   */
#define ID_ALLOC_ERR      3          /* Cannot allocate ID data       */
#define LIST_HEADER       MIN_ID - 1 /* Start of student ID list      */
#define LIST_TRAILER      MAX_ID + 1 /* End of student ID list        */
#define MAX_ID            999999     /* Maximum number of IDs         */
#define MIN_ID            1          /* Minimum number of IDs         */
#define PROGRAM_NUMBER    6          /* Assigned program number       */
#define PROGRAMMER_NAME   "Norris"   /* Programmer's last name        */
#define QUIT              0          /* Quit entering of ID numbers   */
#define TRAILER_ALLOC_ERR 2          /* Cannot allocate trailer data  */

/**********************************************************************/
/*                          Program Structure                         */
/**********************************************************************/
/* Student ID numbers                                                 */
struct student_id
{
   int               student_id; /* ID number of the student          */
   struct student_id *p_next_id; /* Point to the next student ID      */
};
typedef struct student_id STUDENT_ID;

/**********************************************************************/
/*                         Function Prototypes                        */
/**********************************************************************/
void print_heading();
   /* Print the program's heading                                     */
void print_instructions();
   /* Print the program's instructions                                */
char get_response();
   /* Get the response to create a list of student IDs                */
STUDENT_ID *create_list();
   /* Create an empty link list with header and trailer               */
void insert_student_id(STUDENT_ID *p_id_list, int student_id);
   /* Insert student IDs into the list                                */
void print_student_id(STUDENT_ID *p_id_list);
   /* Print the student ID list                                       */
int  get_student_count(STUDENT_ID *p_id_list);
   /* Get the number of student IDs in the list                       */
void sort_student_ids(STUDENT_ID *p_id_list, int number_student);
   /* Sort the student ID list in ascending order                     */
void remove_duplicates(STUDENT_ID *p_id_list);
   /* Remove any duplicate IDs in the list                            */

/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int        student_id;   /* The ID number for the student          */
   STUDENT_ID *p_id_list,   /* Point to the list of student ID        */
              *p_id_number; /* Point to all the IDs in the list       */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing student ID list until the user enter 'n'        */
   while(print_instructions(), get_response() == 'y')
   {
      /* Create a new link list                                       */
      p_id_list = create_list();

      /* Loop processing student IDs until the user choose to quit   */
      while(printf("Enter the next student id (%d to quit): ", QUIT),
         scanf("%d", &student_id), student_id > LIST_HEADER)
      {
         if (student_id >= LIST_TRAILER)
         {
            printf("     Id rejected - it cannot exceed %d", MAX_ID);
            printf("\n");
         }
         else
            insert_student_id(p_id_list, student_id);
      }

      /* Print the linked list and it's length                        */
      printf("\nThe unsorted student id list, as entered, is:");
      print_student_id(p_id_list);
      printf("\nThe length of the unsorted student id list is: %d",
         get_student_count(p_id_list));

      /* Sort the ID numbers and print the length of the linked list  */
      printf("\n\nThe student id list, sorted ascending by id, is:");
      sort_student_ids(p_id_list, get_student_count(p_id_list));
      print_student_id(p_id_list);
      printf("\nThe length of the sorted student id list is: %d",
         get_student_count(p_id_list));
      printf("\n");

      /* Remove all duplicate student ID numbers and print the length */
      /* of the linked list                                           */
      remove_duplicates(p_id_list);
      printf("\nThe student id list, with duplicate id's removed, "
         "sorted ascending by id, is:");
      print_student_id(p_id_list);
      printf("\nThe length of the cleaned and sorted student id list " 
         "is: %d", get_student_count(p_id_list));

      /* Release allocate memory for each student id from the         */
      /* linked list                                                  */
      while(p_id_list != NULL)
      {
         p_id_number = p_id_list;
         p_id_list   = p_id_list->p_next_id;
         free(p_id_number);
      }
   } 

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for using this program.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the Program Heading                      */
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
/*                       Print the Instructions                       */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n");
   printf("\n    This program maintains a list of students by their");
   printf("\n    id number.  After entry of all id's, it sorts them");
   printf("\n    into ascending order, then removes all duplicates.");
   return;
}

/**********************************************************************/
/*             Get the Response for Making a Linked List              */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Store a 'y' or 'n' character                  */

   do
   {
      printf("\n\nDo you want to enter another student id list "); 
      printf("(y or n): ");
      scanf ("%1s", &response[0]);
      response[0] = tolower(response[0]);      
   }   
   while(response[0] != 'y' && response[0] != 'n');
   return response[0];
}

/**********************************************************************/
/*         Create an Empty Link List With Header and Trailer          */
/**********************************************************************/
STUDENT_ID *create_list()
{
   STUDENT_ID *p_new_list; /* Points to new linked list               */

   if((p_new_list = (STUDENT_ID *) malloc(sizeof(STUDENT_ID))) == NULL)
   {
      printf("\nError #%d occurred in create list.", HEADER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list header.");
      printf("\nThe program is aborting.");
      exit(HEADER_ALLOC_ERR);
   }
   p_new_list->student_id = LIST_HEADER;

   if((p_new_list->p_next_id = (STUDENT_ID *) malloc(sizeof
      (STUDENT_ID))) == NULL)
   {
      printf("\nError #%d occurred in create list.", TRAILER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list trailer.");
      printf("\nThe program is aborting.");
      exit(TRAILER_ALLOC_ERR);
   }
   p_new_list->p_next_id->student_id = LIST_TRAILER;
   p_new_list->p_next_id->p_next_id  = NULL;

   return p_new_list;  
}

/**********************************************************************/
/*                 Insert Student ID into Linked List                 */
/**********************************************************************/
void insert_student_id(STUDENT_ID *p_id_list, int student_id)
{
   STUDENT_ID *p_new_student; /* Point to new student ID number       */

   if((p_new_student = (STUDENT_ID *) malloc(sizeof(STUDENT_ID))) == 
                                                                   NULL)
   {
      printf("\nError #%d occurred in insert student.", ID_ALLOC_ERR);
      printf("\nCannot allocate memory for the list trailer.");
      printf("\nThe program is aborting.");
      exit(ID_ALLOC_ERR);
   }
   p_new_student->student_id = student_id;
   p_new_student->p_next_id  = p_id_list->p_next_id;
   p_id_list->p_next_id      = p_new_student;
   

   return;
}

/**********************************************************************/
/*                Print Student ID in the Linked List                 */
/**********************************************************************/
void print_student_id(STUDENT_ID *p_id_list)
{
   if (p_id_list->p_next_id->student_id == LIST_TRAILER)
      printf("\n    The student id list is empty.");
   else
   {
      while(p_id_list              = p_id_list->p_next_id, 
            p_id_list->student_id != LIST_TRAILER)
         printf("\n                        %6d", p_id_list->student_id);
   }
   return;
}

/**********************************************************************/
/*           Get Number of Student IDs from the Linked List           */
/**********************************************************************/
int get_student_count(STUDENT_ID *p_id_list)
{
   int number_student = 0; /* Number of student IDs in the list       */

   while(p_id_list              = p_id_list->p_next_id, 
         p_id_list->student_id != LIST_TRAILER)
      number_student += 1;
   return number_student;
}

/**********************************************************************/
/*                 Sort Student IDs in the Linked List                */
/**********************************************************************/
void sort_student_ids(STUDENT_ID *p_id_list, int number_student)
{
   int        id_counter;      /* Number of student ID numbers        */
   STUDENT_ID *p_student,      /* Point to the current ID number      */
              *p_temp_student; /* Point to temporary student for swap */

   for (id_counter = 0; id_counter < (number_student - 1); id_counter++)
   {
      p_student = p_id_list;
      while(p_student->p_next_id->p_next_id->student_id < LIST_TRAILER)
      {
         if (p_student->p_next_id->student_id > p_student->p_next_id
                                                ->p_next_id->student_id)
         {
            p_temp_student = p_student->p_next_id->p_next_id;
            p_student->p_next_id->p_next_id
                           = p_student->p_next_id->p_next_id->p_next_id;
            p_temp_student->p_next_id
                           = p_student->p_next_id;
            p_student->p_next_id
                           = p_temp_student;
         }
         p_student = p_student->p_next_id;
      }
   }
   return;
}

/**********************************************************************/
/*                        Remove Duplicate IDs                        */
/**********************************************************************/
void remove_duplicates(STUDENT_ID *p_id_list)
{
   STUDENT_ID *p_current  = p_id_list->p_next_id, 
                                          /* Point to each ID numbers */
              *p_previous = p_id_list;    /* Point to the previous ID */

   while(p_current->student_id < LIST_TRAILER)
   {
      if (p_previous->student_id == p_current->student_id)
      {
         printf("\nDeleting the duplicate student id: %2d",
            p_current->student_id);
         p_previous->p_next_id = p_current->p_next_id;
         free(p_current);
         p_current             = p_previous->p_next_id;
      }
      else
      {
         p_previous = p_current;
         p_current  = p_current->p_next_id;
      }
   }
   return;
}

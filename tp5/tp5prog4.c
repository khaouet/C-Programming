/**
  * @Source file : tp5prog3.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : dynamic variables
  * @description :
  *
  *
  *
  * ---------------------------------------------------------------------------
  */

  /** Remainder : a variable is an entity of a programming language having:
                     - a type
                     - a name : called also identifier
                     - a value
                     - a memory address
                     - a size in bytes
                    a variable may be not initialized */


  /** new concept : a dynamic variable is an entity of a programming language having:
                     - a type
                     - a value
                     - a memory address
                     - a size in bytes
                     - is allocated in execution time int the heap of the memory
                     - handled by a pointer
                  */

/* realloc example: rememb-o-matic */
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main ()
{
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

  do {
     printf ("Enter an integer value (0 to end): ");
     scanf ("%d", &input);
     count++;

     more_numbers = (int*) realloc (numbers, count * sizeof(int));

     if (more_numbers!=NULL) {
       numbers=more_numbers;
       numbers[count-1]=input;
     }
     else {
       free (numbers);
       puts ("Error (re)allocating memory");
       exit (1);
     }
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  return 0;
}

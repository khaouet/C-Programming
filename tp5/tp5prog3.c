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


#include <stdio.h>
#include <stdlib.h>


int golbal_var = 10;

int get_global_var_value(void);
void increment(int *x);


/* calloc example */

int main ()
{
  int nb_element,n;
  int * pData; // pData is a int pointer
  printf ("Amount of numbers to be entered: ");
  scanf ("%d",&nb_element);
  // calloc take 02 parameters : nb of elements to be allocated and
  // the second parameter the size of each allocation element
  // using calloc provide a contiguous array of elements of the desired size

  pData = (int*) calloc (nb_element,sizeof(int));

  pData = (int*) malloc(nb_element*sizeof(int));

  if (pData != NULL)
  {
    for (n=0;n<nb_element;n++)
      {
        printf ("element #%d: %d\n",n+1,pData[n]);
      }

      for (n=0;n<nb_element;n++)
      {
        printf ("Enter number #%d: ",n+1);
        scanf ("%d",&pData[n]);
      }

      printf ("You have entered: ");
      for (n = 0;n < nb_element; n++)
      {
          printf ("%d ",pData[n]);
      }

      free (pData);
  }
  return 0;
}





//int main()
//{
//    // local variable in a main function
//    int x = 10;
//    {
//        int x = 5;
//        printf("%d\n",x);
//        golbal_var ++;
//        printf("%d\n",get_global_var_value());
//        increment(&x);
//    }
//    printf("%d\n",x);
//    return 0;
//}



int get_global_var_value(void)
{

    return golbal_var;
}

void increment(int *x)
{
    *x++;
}

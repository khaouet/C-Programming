 /**
  * @Source file : tp5prog1.c
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



#include <stdio.h>
#include <stdlib.h>

/**
+------------+
| ptr        |
+------------+-----------------------
                                    |
                                    V
                                    +-------------------------+
                                    |            100          |
                                    +-------------------------+

*/

int main()
{

    /**
        concept de la variable dynamique :
                     - a type
                     - a value
                     - a memory address
                     - a size in bytes
    */

    int *ptr = NULL;

    ptr = (int*) malloc(sizeof(int)); // a dynamic variable is created using a pointer ptr
    // malloc va allouer une zone mémoire non initialized
    // ptr is used to handle the created dynamic variable
    *ptr = 100;
    printf("%d\n",*ptr);
    // libérer la mémoire à l'aide de la fonction free
    free(ptr); // destruction de la variable dynamique

    // creation d'un tableau dynamique
    ptr = (int*) malloc(10*sizeof(int));
    for(int i = 0 ; i < 10 ; i++)
    {
        //ptr[i] = i;
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        printf("%d ",ptr[i]);
    }

    free(ptr); // liberer la mémoire


    return 0;
}

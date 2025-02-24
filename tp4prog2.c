/**
  * ---------------------------------------------------------------------------
  * @Source file : tp4prog1.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : Pointers in C
  * @description : A pointer is a variable that stores the memory address
  *                of another variable. Instead of holding a direct value,
  *                it holds the location where that value is stored in memory.
  *
  * ---------------------------------------------------------------------------
  */
#include <stdio.h>
#include <stdlib.h>

/**
  A struct declaration defines a new data type.
  the struct keyword is used for it's declaration.
  */
struct Point {
    int x; // X-coordinate
    int y; // Y-coordinate
};


int main()
{
    int *pi;    // A pointer to an integer
    char *c;   // A pointer to a character
    float *f;  // A pointer to a float
    void *ptr1; // A pointer to
    int **pp;   // A pointer to a pointer to an integer

    int a = 10, b = 100;
    int *p = &a; // The pointer <p> holds the address of <a>
/**
        @p              type:int*
        +------------------+
     p  | 000000000061FE0C |
        +------------------+  ------+
      p <-- @a                      |
                                    v
                                    @a          type:int
                                   +--------------------+
                        *p <==> a  |     10             |
                                   +--------------------+

*/

    struct Point p1 = { 10 , 20};
    struct Point *ptr = &p1;  // Pointer to a struct

    /** Members of a struct are accessed using the dot (.) operator
        for regular variables  or the arrow (->) operator for pointers.
      */

    printf("x = %d, y = %d\n", p1.x, p1.y);   // Using dot operator
    printf("x = %d, y = %d\n", ptr->x, ptr->y); // Using arrow operator

    printf("la valeur en memoire pointé par p = %d = %d\n",*p, a);
    printf("@a = %p = p = %p\n", &a , p);

    *p = 50;
    printf("la valeur en memoire pointé par p = %d = %d\n",*p, a);

    p = &b;
    printf("la valeur en memoire pointé par p = %d\n",*p);
 /**
        @p              type:int*
        +------------------+
     p  | 000000000061FE08 |
        +------------------+  ------+
      p <-- @b                      |
                                    v
                                    @b          type:int
                                   +--------------------+
                        *p <==> b  |     100            |
                                   +--------------------+

*/
    printf("la valeur en memoire pointé par p = %d = %d\n",*p, b);
    printf("@b = %p = p = %p\n", &b , p);
    return 0;
}

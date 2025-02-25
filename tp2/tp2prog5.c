/**---------------------------------------------------------------------------
  Source file : tp2prog5.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : arrays using C language
-----------------------------------------------------------------------------*/
/** rand example: initialize an array with random numbers */

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define MAX_T_SIZE 100


int main()
{
    int i; /** index to iterate the array */
    float t[MAX_T_SIZE];
    unsigned int n; /** nb elements of array t  */
    /** loop to control input n must be between 1 and MAX_T_SIZE */
    do {
        printf("array size n = ");
        scanf("%u",&n);
    } while((n <= 0) || (n > MAX_T_SIZE));
    /* initialize random seed: */
    srand (time(NULL));
    /** initialize t array with random numbers*/
    for(i = 0; i < n ; i++)
    {
        t[i] = (float)rand()/RAND_MAX;
    }
    /** print t array as a list after initialization */
    printf("[");
    for(i = 0; i < n-1 ; i++)
    {
       printf("%.2f, ",t[i]);
    }
    printf("%.2f]\n",t[i]);
    printf("RAND_MAX = %u",RAND_MAX);
    getchar();
    getchar();
    return 0;
}

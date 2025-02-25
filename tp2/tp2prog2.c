/**---------------------------------------------------------------------------
  Source file : tp2prog2.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : arrays using C language
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**
        Declaration & Initialization of arrays in C;
    */

    char voyelles[] = {'A','E','I','O','U','Y'};
    int t[] = {-1, 4, 51, 37, 22, 56, 100, -256, -33};
    int z[5] = {-3, -2, -1};
    int n[7] = {0};
    int i;
    /** i is an index from 0 to size_of_array - 1 */
    for( i = 0; i < sizeof(voyelles) ; i ++)
    {
        printf("voyelles[%d] = %c \n", i , voyelles[i]);
    }
    /**
        caution: C compiler does'nt control limits
    */
    printf("%d\n",i);

    t[-1]= 150;
    i = 0;
    printf("%d\n",i);
    for( i = 0; i <= sizeof(t)/sizeof(int)+1 ; i++)
    {
        printf("t[%d] = %d \n", i , t[i]);
    }
    printf("t[%d] = %d \n", -1 , t[-1]);
    t[1000] = -10000;
    printf("t[%d] = %d \n", 1000 , t[1000]);

    for( i = 0; i < sizeof(z)/sizeof(int) ; i++)
    {
        printf("z[%d] = %d \n", i , z[i]);
    }
    return 0;
}

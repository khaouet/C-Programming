/*---------------------------------------------------------------------------
  Source file : tp0prog11.c
  Author      : --
  Class       : --
  Brief       :
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , j, d, r;
    float f;

    i = 15;
    j = 4;
    d = i / j;
    r = i % j;

    printf("i=%d , j = %d , d= %d r =%d\n", i, j, d, r);
    f = (float)(i / j);
    printf("%g\n", f);
    printf("%g\n", (float) i / j);
    printf("%g\n", i / (float) j);
    printf("%g\n", (float) i / (float) j);

    /* to do */
    /*
        comment all the above instructions
        correct the program if any syntax errors existes
        use the caste operator to print the following expressions:
        f = (float) i / j
        f = i / (float) j
        f = (float) i / (float) j
        compare all the results
        conclude!

    */

    return 0;
}

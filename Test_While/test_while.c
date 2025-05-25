#include <stdio.h>
#include <stdlib.h>

#define LONG_CONST 400000

int main()
{
    /** Attention */
    short i; /* sur 16 bits */
    for(i = 0; i < LONG_CONST ; i++)
    {
        printf("%d\t",i);
    }
    printf("%d\t",i); /* n'est jamais executé*/
    return 0;
}

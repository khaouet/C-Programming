/**---------------------------------------------------------------------------
  Source file : tp2prog1.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : arrays using C language
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define NB_VOYELLES 6
#define NB_LETTERS 26
int main()
{
    /* array declaration <type> <array_name>[<size_of_array>]*/
    /**
        <type>      : char | int | float | ....
        <array_name>: identifier
        <size_of_array>: constante litterale de type entier
                         | #define N 100
                         | const unsigned  N = 100;

    */
    const unsigned int N = 15;
    int Z=15;
    char str[80];
    int t[10];
    float temperature[100];
    double sinusoide[200];
    const int _t[5];
    char voyelles[NB_VOYELLES];
    char consonnes[NB_LETTERS - NB_VOYELLES];
    double pressure[N];
    int _tZ[Z];

    printf("taille str = %d\n",(int)sizeof(str));
    printf("taille t = %d\n",(int)sizeof(t));
    printf("nb elements de  t = %d\n",(int)sizeof(t)/(int)sizeof(int));
    return 0;
}

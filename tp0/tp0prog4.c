/*---------------------------------------------------------------------------
  Source file : tp0prog4.c
  Author      : --
  Class       : --
  Object      : This program demonstrates arithmetic type usage
                for the C language
-----------------------------------------------------------------------------*/

/* Inclusion of standard libraries */
/* stdio.h is a header file        */
/* stdlib.h is a header file       */

#include <stdio.h>    // standard library for input/output
#include <stdlib.h>   // standard library

/* --------------------------------------------------------------------------

-----------------------------------------------------------------------------*/
/*

short <==> short int
signed short <==> signed short int : a signed int declaration
unsigned short <==> unsigned short int : an unsigned int declaration
short <==> signed short


int <==> signed int
unsigned int

long <==> long int
signed long <==> signed long int
unsigned long <==> unsigned long int

long long <==> long long int
signed long long <==> signed long long int
unsigned long long <==> unsigned long long int

*/

int main()
{
    /* int is a keyword used to declare signed integer variables */
    int d = 69;        // Initialization of a signed int with a decimal literal constant
    int o = 0105;      // Initialization of a signed int with an octal literal constant
    int x = 0x45;      // Initialization of a signed int with an hexadecimal literal constant
    int X = 0X45;      // Initialization of a signed int with an hexadecimal literal constant
    int b = 0b1000101; // C23 compiler only
                       // Initialization of a signed int with a binary literal constant

    int n ;        // Initialization of a signed int with a negative decimal literal constant

    n = 0b11111111111111111111111111111111;
    /* %d is used by printf function to interpret an integer variable as a signed decimal */
    /* %i is used by printf function to interpret an integer variable as a signed decimal */

    /* all the above variable have the same value */
    printf("%3d %3d %3d %3d %3d\n", d,o,x,X,b);

    /* prints to the the screen the value of each variable with the corresponding formatter */
    /*
       %d : is used for signed decimal formatting
       %o : is used for octal (base 8) formatting
       %x : is used for hexadecimal (base 16) formatting
       %X : is used for hexadecimal (base 16) formatting
    */
    printf("%3d %3o %3x %3X %3d\n", d,o,x,X,b); /* there's no formatter for binary format */

    /* prints the value of n using decimal formatting  */
    printf("n= %d\n",n);
    /* prints the value of n using hexadecimal formatting  */
    printf("n= %x\n",n);
    /* prints the value of n using hexadecimal formatting  */
    printf("n= %X\n",n);
    /* prints the value of n using octal formatting  */
    printf("n= %o\n",n);
    /* negative values are represented in two complement coding
       if n is a positive value, -n = ~n + 1
       ~ designates the operator that gives the bit complement of n
    */
    n = 1;
    /* -n is equal to ~n + 1   */
    printf("n = %d\n", n);
    printf("-n = %d , ~n +1 = %d\n",-n , ~n + 1 );
    printf("size of an int in bytes = %d\n", (int) sizeof(n));

    /* Conclusion : a variable is an entity of a programming language having:
                     - a type
                     - a name : called also identifier
                     - a value
                     - a memory address
                     - a size in bytes
                    a variable may be not initialized */
    printf("type of n : int\nname of n : n\nvalue of n : %d\nMemory address of n : %p\nSize in byte(s) of n : %d",
             n, &n, (int) sizeof(n));

    return 0;
}

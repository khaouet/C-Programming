/*---------------------------------------------------------------------------
  Source file : tp0prog5.c
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
#include <float.h>
#include <math.h>
/* --------------------------------------------------------------------------

-----------------------------------------------------------------------------*/

/*
  Real floating types :
  float : 32 bits
  double : 64 bits
  long double : ?

*/


int main()
{
    /* float is a keyword used to declare Real floating types variables */
    float f1 = .55;
    float x = 2.56e-5;  // <=> 2.56 x 10^-5 = 0.0000256 Real floating literal constant in scientific notation
    float r = 10.4378;
    float u = 48e6;
    float v = 10.f;
    float w = 10.2f;
    float s = 0.55;
    float z;

    /* prints to the the screen the value of each variable with the corresponding formatter */
    /*
       %f : is used for floating types formatting
       %g : is used for floating types formatting
       %e : is used for floating types formatting

    */

    printf("f = %f\nx = %f\nr = %f\nu = %.2f\nv = %.0f\nw = %.1f\ns = %.3f\nz = %f\n", f1,x,r,u,v,w,s,z);
    printf("-------------------------------------------\n");
    printf("f = %g\nx = %g\nr = %g\nu = %g\nv = %g\nw = %g\ns = %g\nz = %g\n", f1,x,r,u,v,w,s,z);
    printf("-------------------------------------------\n");
    printf("f = %e\nx = %e\nr = %e\nu = %e\nv = %e\nw = %e\ns = %e\nz = %e\n", f1,x,r,u,v,w,s,z);



    return 0;
}

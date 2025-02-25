/*---------------------------------------------------------------------------
  Source file : tp0prog13.c
  Author      : --
  Class       : --
  Object      : conditional expression
-----------------------------------------------------------------------------*/

/* Inclusion of standard libraries */
/* stdio.h is a header file        */
/* stdlib.h is a header file       */

#include <stdio.h>    // standard library for input/output
#include <stdlib.h>   // standard library

/* ------------------------------------------------------------------------------------------------
   An expression is a sequence of operators and their operands,
   that specifies a computation.
   examples
   2 + 4
   printf("%d",4)

   value categories : (lvalue, non-lvalue object, function designator)
                      classify expressions by their values
   order of evaluation of arguments and subexpressions :
                       specifies the order in which intermediate
                       results are obtained
   Operators :
   | assignment	 | increment | arithmetic | logical | comparison | member | other        |
   |             | decrement |            |         |	         | access |			     |
   +-------------+-----------+------------+---------+------------+--------+--------------+
   |    a = b    |     ++a   |     +a     |   !a    |	a == b   |  a[b]  |	a(...)		 |
   |    a += b   |     --a   |     -a     | a && b  |	a != b   |  *a    |	a, b		 |
   |    a -= b   |     a++   |    a + b   | a || b  |	a < b    |  &a    |(type) a		 |
   |    a *= b   |     a--   |    a - b   |         |	a > b    |  a->b  |	a ? b : c    |
   |    a /= b   |           |    a * b   |         |	a <= b   |  a.b   |	sizeof		 |
   |    a %= b   |           |    a / b   |         |	a >= b   |        |			     |
   |    a &= b   |           |    a % b   |         |	         |        |			     |
   |    a |= b   |           |     ~a     |         |	         |        |			     |
   |    a ^= b   |           |    a & b   |         |	         |        |			     |
   |    a <<= b  |           |    a | b   |         |	         |        |			     |
   |    a >>= b  |           |    a ^ b   |         |	         |        |			     |
   |             |           |    a << b  |         |	         |        |			     |
   |             |           |    a >> b  |         |	         |        |			     |
--------------------------------------------------------------------------------------------------*/

/*
   in C language:
        - an expression is evaluated to be different from Zero != 0 ==> True
        - an expression is evaluated to Zero == 0 ==> False
        - logical expressions are always evaluated to One 1 if they are True else they are evaluated to 0 that means False
*/


int main()
{
    /* Declaration of 2 non initialized integer variables */
    int a, b ,c , r  ;
    /* prints the message "a=" to the screen without return to a new line */
    printf("a = ");
    /* reads to the address memory of the variable named "a" an integer value */
    scanf("%d",&a);
    /* prints the message "b=" to the screen without return to a new line */
    printf("b = ");
    /* reads to the address memory of the variable named "b" an integer value */
    scanf("%d",&b);

    printf("c = ");
    /* reads to the address memory of the variable named "b" an integer value */
    scanf("%d",&c);

    r = (a >= b)? (( a>= c)? a: c) : ((b >= c)? b : c) ;

    printf("max(a=%d,b=%d, c=%d)=%d",a,b,c,r) ;

    return 0;
}

/*---------------------------------------------------------------------------
  Source file : tp0prog12.c
  Author      : --
  Class       : --
  Object      : comparison / logic Expressions
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
    int a, b ;
    /* prints the message "a=" to the screen without return to a new line */
    printf("a = ");
    /* reads to the address memory of the variable named "a" an integer value */
    scanf("%d",&a);
    /* prints the message "b=" to the screen without return to a new line */
    printf("b = ");
    /* reads to the address memory of the variable named "b" an integer value */
    scanf("%d",&b);

    printf("a=0x%x\n",a);
    printf("b=0x%x\n",b);

    /* comparison operators */

    printf("a = %d, b = %d , a == b evaluated to %d\n", a, b, a == b);
    printf("a = %d, b = %d , a != b evaluated to %d\n", a, b, a != b);
    printf("a = %d, b = %d , a >= b evaluated to %d \n", a, b, a >= b);
    printf("a = %d, b = %d , a <= b evaluated to %d \n", a, b, a <= b);
    printf("a = %d, b = %d , a > b evaluated to %d \n", a, b, a > b);
    printf("a = %d, b = %d , a < b evaluated to %d \n", a, b, a < b);

    /* logical operators */

    printf("a = %d, b = %d , (a == b) && ( a != 3) evaluated to %d\n", a, b, (a == b) && ( a != 3));
    printf("a = %d, b = %d , (a == b) || ( a != 3) evaluated to %d\n", a, b, (a == b) || ( a != 3));
    printf("a = %d, b = %d , !(a != b) && ( a != 3) evaluated to %d\n", a, b, !(a != b) && ( a != 3));


    /* Instructions : execute this code with different values of a and b :

     */
     /*
       Questions: evaluate the following expressions
       a = 3, b = 5
           1-  (a >= b) || (b >= 4)
           2-  !a & !b
           3-  !(b-a-2)
           5-  ((a + b) - b/a) == 10
           6-  (a + b) - b/a == 10
           7-  !(a / (a * b))
           8-  !a/(a * b)
           9-  (a && b) && ( a & 0)
          10-  (0xFF) || (a / b == 0)
          11-  (a / b == 0)

     */

    return 0;
}

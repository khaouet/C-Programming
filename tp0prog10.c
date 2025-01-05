/*---------------------------------------------------------------------------
  Source file : tp0prog10.c
  Author      : --
  Class       : --
  Object      : Assignement Expressions
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

    /* assignement operators */
    a+=b; /* <==> a = a + b */
    printf("a = %d, a = 0x%x\n", a, a);
    a-=b;  /* <==> a = a - b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a*=b;  /* <==> a = a * b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a/=b;  /* <==> a = a / b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a%=b;  /* <==> a = a % b  */
    printf("a = %d, a = 0x%x\n", a, a);

    /* assignments for bitwise operators /*/
    a&=b;  /* <==> a = a & b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a|=b;  /* <==> a = a | b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a^=b;  /* <==> a = a ^ b  */
    printf("a = %d, a = 0x%x\n", a, a);
    a<<=b; /* <==> a = a << b */
    printf("a = %d, a = 0x%x\n", a, a);
    a>>=b; /* <==> a = a >> b */
    printf("a = %d, a = 0x%x\n", a, a);

    /* Instructions : execute this code with :
        a = 15   and  b = 1
        a = 256  and  b = 2
        a = 1024 and  b = 4
     */


    return 0;
}

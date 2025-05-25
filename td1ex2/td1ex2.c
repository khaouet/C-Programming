#include <stdio.h>
#include <stdlib.h>

/**
    Exercice 2
    Écrire plus simplement l’instruction suivante :
    z = (a > b ? a : b) + (a <= b ? a : b) ;

**/

int main()
{
    int a,b,z;
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    z = ((a > b) ? a : b) + ((a <= b) ? a : b);
    printf("z = %d = %d + %d\n",z,a,b);
    /**
        ((a > b) ? a : b) + ((a <= b) ? a : b)
        <==>
        a + b
    **/
    printf("%d", \
      ((a > b) ? a : b) + ((a <= b) ? a : b) == (a + b));
    return 0;
}

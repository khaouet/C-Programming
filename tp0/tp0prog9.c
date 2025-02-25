#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mychar; /* %c */
    int n;       /* %d %i %x %o %X */
    float r;     /* %f %g %e */

    printf("c = ");
    scanf("%c",&mychar);
    printf("scanned value from keyboard is c = %c\n", mychar);

    printf("n = ");
    scanf("%d",&n);
    printf("scanned value from keyboard is n = %d\n", n);

    printf("n (octal) = ");
    scanf("%o",&n);
    printf("scanned value from keyboard is n = %d\n", n);

    printf("n (hex) = ");
    scanf("%x",&n);
    printf("scanned value from keyboard is n = %d\n", n);

    printf("r = ");
    scanf("%f",&r);
    printf("scanned value from keyboard is r = %f\n", r);

    printf("r = ");
    scanf("%e",&r);
    printf("scanned value from keyboard is r = %f\n", r);

    printf("r = ");
    scanf("%g",&r);
    printf("scanned value from keyboard is r = %f\n", r);

    return 0;
}

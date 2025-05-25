#include <stdio.h>
#include <stdlib.h>

/**
Ecrire un programme qui lit un réel x et calcule le polynôme
P(x) = x^5 + 3x^4 +2x^3 + x^2 + 3x + 1
*/
int main()
{
    double x;
    printf("x = ");
    scanf("%lf",&x);
    printf("P(%g) = %g",x , pow(x,5) + 3 * pow(x,4) + 2 * pow(x,3) + pow(x,2) + 3 * x + 1);
    return 0;
}

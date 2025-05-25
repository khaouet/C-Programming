#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Ecrire un programme qui lit le rayon d’un cercle puis calcule et affiche son périmètre et sa
surface
*/
/**          01234567890123456789012345678901234567890123456789 **/
#define PI 3.14159265358979323846264338327950288419716939937510


int main()
{
    double rayon;
    const double Pi = (double)3.14159265358979323846264338327950288419716939937510;
    const double pi = acos(-1);
    printf("PI = %.20lf\n",PI);
    printf("Pi = %.20lf\n",Pi);
    printf("pi = %.20lf\n",pi);

    printf("Surface et Périmètre d'une Cerle\n");
    printf("Rayon = ");
    scanf("%lf",&rayon);
    printf("%lf\n",rayon);
    printf("Périmètre = %g\n",2*Pi*rayon);
    printf("Surface = %g\n",Pi*rayon*rayon);
    printf("Surface = %g\n",Pi*pow(rayon,2));
    printf("%f\n",cos(pi/2));
    printf("%.20lf\n",cos(pi/2));
    printf("%g\n",cos(pi/2));
    return 0;
}

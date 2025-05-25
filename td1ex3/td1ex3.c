#include <stdio.h>
#include <stdlib.h>
/**
    n étant de type int, écrire une expression qui prend la valeur :
    -1 si n est négatif,
     0 si n est nul,
     1 si n est positif.
    pair/impair
**/

int main()
{
    int n;
    const char* negatif = "Negatif";
    const char* nulle = "Nulle";
    const char* positif = "Positif";
    const char* pair = "pair";
    const char* impair = "impair";

    printf("n = ");
    scanf("%d",&n);
    printf("%d\n",(n < 0)? -1 : (n == 0)? 0: 1);
    printf("%s\n",(n < 0)? negatif :(n == 0)? nulle : positif);
    printf("%s\n",(n % 2)? impair : pair);
    printf("%s\n",(n & 1)? impair : pair);

    return 0;
}












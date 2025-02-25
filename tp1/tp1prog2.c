#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288419716939937510


int main()
{
    const double pi = 3.14159265358979323846264338327950288419716939937510;
    char c;
    int val; /* Declration d'une variable entière*/
    int n;
    double angle;
    printf("val = ");
    scanf("%d",&val); /* read a value from the keybord  */
    getchar();
//    printf("Using if without else\n");
//    if (val != 0)
//    {
//        printf("1: val is not equals to zero\n");
//    }
    printf("press any key to continue...");
    getchar();
    printf("Using if with else\n");
    if (!val) /* <==> if (val == 0) */
    {
        printf("0: val is equals to zero\n");
    }
    else
    {
        printf("2: val is not equals to zero\n");
    }
//    printf("Scan a character : ");
//    c = getchar();
//    switch(c)
//    {
//        case 'a':
//        case 'A':
//        case 'o':
//        case 'O':
//        case 'u':
//        case 'U':
//        case 'i':
//        case 'I':
//        case 'e':
//        case 'E':
//        case 'y':
//        case 'Y':
//            printf("%c est une voyelle\n",c);
//            break;
//        default:
//            printf("%c est une consonne",c);
//    }
    printf("press any key to continue...");
    getchar();
    n=0;
    printf("Using while statement : 1\n");
    while( n < val )
    {
        printf("iter %d\n",n++);
        //n++; /* <==> n = n + 1 */
    }
    printf("Using do .. while statement \n");
    n = 0;
    do {
        printf("iter %d\n",n++);
    } while( n < val);

    printf("Using for statement \n");
    for( angle = 0 ; angle  <= pi / 2 ; angle+=PI/12)
    {
        printf("cos(%lf) = %lf\n",angle, cos(angle));
    }



    return 0;
}

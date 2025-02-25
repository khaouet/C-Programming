#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val; /* Declration d'une variable entière*/
    int n;
    printf("val = ");
    scanf("%d",&val); /* read a value from the keybord  */
    getchar();
    printf("Using if without else\n");
    if (val != 0)
    {
        printf("1: val is not equals to zero\n");
    }
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
    printf("press any key to continue...");
    getchar();
    printf("Using switch statement\n");
    switch(val)
    {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("2\n");
            break;
        case 3:
        case 4:
            printf("3 or 4\n");
            break;
        default:
            printf("not 1 and not 2 and not 3 and not 4\n");

    }
    printf("press any key to continue");
    getchar();
    n=0;
    printf("Using while statement : 1\n");
    while(n < val )
    {
        printf("iter %d\n",n);
        n++;
    }
    printf("press any key to continue");
    getchar();
    printf("Using while statement : 2\n");
    while(++n < val )
    {
        printf("iter %d\n",n);
    }
    printf("press any key to continue");
    getchar();
    printf("Using while statement : 3\n");
    while(n++ < val )
    {
        printf("iter %d\n",n);
    }
    printf("press any key to continue");
    getchar();
    printf("Using do .. while statement \n");
    n = 0;
    do {
        printf("iter %d\n",n++);
    } while( n < val);

    printf("Using for statement \n");
    for( n = 0 ; n < val ; n++)
    {
        printf("iter %d\n",n);
    }

    /* infinite loop statements */
    /*
    while(1)
    {

    }

    do {

    } while(1)

    for(;;)
    {

    }
    */
    return 0;
}

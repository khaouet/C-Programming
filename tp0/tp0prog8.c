#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    short sa, sb;
    long la, lb;
    long long ll_a, ll_b;

    unsigned int u_a;
    unsigned int u_b;

    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);

    printf("scanned values from keyboard are a = %d , b= %d\n", a ,b);

    printf("sa = ");
    scanf("%hd",&sa);
    printf("sb = ");
    scanf("%hd",&sb);

    printf("scanned values from keyboard are sa = %d , sb= %d\n", sa ,sb);

    printf("la = ");
    scanf("%ld",&la);
    printf("lb = ");
    scanf("%ld",&lb);

    printf("scanned values from keyboard are la = %ld , lb= %ld\n", la ,lb);

    printf("ll_a = ");
    scanf("%lld",&ll_a);
    printf("ll_b = ");
    scanf("%lld",&ll_b);

    printf("scanned values from keyboard are ll_a = %lld , ll_b= %lld\n", ll_a ,ll_b);


    printf("u_a = ");
    scanf("%u",&u_a);
    printf("u_b = ");
    scanf("%u",&u_b);

    printf("scanned values from keyboard are u_a = %u , u_b= %u\n", u_a ,u_b);

    return 0;
}

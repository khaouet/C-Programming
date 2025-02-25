#include <stdio.h>
#include <stdlib.h>

int main()
{
    short s_n; /* Declaration of a signed short varibale*/
    unsigned short us_n; /* Declaration of a unsigned short varibale*/
    int n;
    unsigned u_n;
    long l_n;
    unsigned ul_n;
    long long ll_n;
    unsigned long long ull_n;

    printf("size of short %d %d\n", (int) sizeof(s_n), (int) sizeof(us_n) );
    printf("size of int %d %d\n", (int) sizeof(n), (int) sizeof(u_n) );
    printf("size of long %d %d\n", (int) sizeof(l_n), (int) sizeof(ul_n) );
    printf("size of long long %d %d\n", (int) sizeof(ll_n), (int) sizeof(ull_n) );

    ull_n = 0b1111111111111111111111111111111111111111111111111111111111111111;
    ull_n = 0xFFFFFFFFFFFFFFFF;
    n = ull_n;
    us_n = ull_n;

    printf("ull_n = %-16d n = %-8d us_n = %d\n", ull_n, n , us_n);
    printf("ull_n = %llx n = %-8x us_n = %hx\n", ull_n  , n , us_n);

    return 0;
}

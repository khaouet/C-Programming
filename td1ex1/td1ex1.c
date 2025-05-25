#include <stdio.h>
#include <stdlib.h>

/**
Soit les déclarations suivantes :
int n = 10 , p = 4 ;
long q = 2 ;
float x = 1.75 ;
Donner le type et la valeur de chacune des expressions suivantes :
a) n + q
b) n + x
c) n % p +q
d) n < p
e) n >= p
f) n > q
g) q + 3 * (n > p)
h) q && n
i) (q-2) && (n-10)
j) x * (q==2)
k) x *(q=5)

**/



int main()
{

    short int n = 10 , p =4;
    int q = 2 ;
    double x = 1.75 ;

//    a) n + q
        printf("%d %d\n",n+q,sizeof(n+q));
//    b) n + x
        printf("%g %d\n",n+x,sizeof(n+x));
//    c) n % p +q
//    d) n < p

        printf("%d %d %d\n",n < p ,sizeof(n),sizeof(n < p));
//    e) n >= p
//    f) n > q
//    g) q + 3 * (n > p)
//    h) q && n
//    i) (q - 2) && (n - 10)
//    j) x * (q == 2)
//    k) x * (q = 5)

    return 0;
}









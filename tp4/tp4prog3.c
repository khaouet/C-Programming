/**
  * ---------------------------------------------------------------------------
  * @Source file : tp4prog3.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : functions in C
  * @description :
  *
  *
  *
  * ---------------------------------------------------------------------------
  */
#include <stdio.h>
#include <stdlib.h>

/* types declarations */
struct Point_t {
    int abs; // X-coordinate structure member
    int ord; // Y-coordinate structure member
};

typedef struct Point_t Point;

/* Functions Declarations */
int pgcd(int a, int b);
void affiche_triangle(int nblig, char c);
Point init(int x, int y);
void affiche_point(Point p);

int main()
{
    int a,b;
    //printf("a="); scanf("%d",&a);
    //printf("b="); scanf("%d",&b);
    //printf("pgcd(%d,%d) = %d\n", a, b , pgcd(a,b)); // function call with effective parameters
    affiche_triangle(5,'+');
    affiche_triangle(4,'*');
    affiche_triangle(10,'@');
    Point A = init(10,15);
    Point B = A;

    affiche_point(A);
    affiche_point(B);

    return 0;
}

/* Function Definition*/

/**
  * @param a int
  * @param b int
  * @retval int
  */

int pgcd(int a, int b)
// a,b functions parameters or arguments formels
// @retval int (the returned value of pgcd is int)
{
    while(a!=b)
    {
        if(a > b)
            a-=b;
        else
            b-=a;
    }
    return a;
}

void affiche_triangle(int nblig, char c)
{
   for(int i = 0 ; i < nblig ; i++)
   {
       for(int j = -1; j < i ; j++)
       {
           printf("%c",c);
       }
       printf("\n");
   }
   // attention pas return
}

Point init(int x, int y)
{
    Point p;
    p.abs = x;
    p.ord = y;
    return p;
}
void affiche_point(Point p)
{
    printf("<%d,%d>\n",p.abs, p.ord);
}

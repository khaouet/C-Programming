/**
  * ---------------------------------------------------------------------------
  * @Source file : tp4prog4.c
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

/* Functions Declaration */

void permut(int *x, int *y);
void symetrique(Point p, Point *pp);
//Point symetrique(Point p);


int main()
{
    int x,y;
    int a=50,b=100;
    Point p = {1,1};
    Point s = {100,200};
    printf("x="); scanf("%d",&x);
    printf("y="); scanf("%d",&y);

    printf("x= %d, y=%d\n", x, y);
    /* reference call*/
    permut(&x,&y);
    printf("x= %d, y=%d\n", x, y);
    printf("a= %d, b=%d\n", a, b);
    permut(&a,&b);
    printf("a= %d, b=%d\n", a, b);

    symetrique(p,&s);
    printf("<%d,%d>", s.abs, s.ord);

    return 0;
}

/* functions definitions */

void permut(int *x, int *y)
{
   int tmp = *x;
   *x = *y;
   *y = tmp;

}

void symetrique(Point p, Point *pp)
{
    pp->abs = - p.abs;
    pp->ord = - p.ord;
}

/**
  * @Source file : tp5prog2.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : dynamic variables
  * @description :
  *
  *
  *
  * ---------------------------------------------------------------------------
  */

  /** Remainder : a variable is an entity of a programming language having:
                     - a type
                     - a name : called also identifier
                     - a value
                     - a memory address
                     - a size in bytes
                    a variable may be not initialized */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    float abs;
    float ord;

} Point;

Point* create_point(const char* str, float abs, float ord);
void affiche(const Point *p);
void liberer(Point *p);

int main()
{
    Point *p;
    p = create_point("A123",1.0,2.0);
    affiche((const Point*)p);
    liberer(p);
    affiche((const Point*)p);
    return 0;
}


Point* create_point(const char* str, float abs, float ord)
{
    Point *p;
    p = (Point*) malloc(sizeof(Point));
    p->abs = abs;
    p->ord = ord;
    p->name  = (char*) malloc(sizeof(str));
    strcpy(p->name,str);
    return p;
}

void affiche(const Point *p)
{
    printf("%s:<%.2f,%.2f>\n", p->name, p->abs, p->ord);
}

void liberer(Point *p)
{
    free(p->name);
    free(p);
}

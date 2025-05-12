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

typedef struct Point_t {
    char* name;
    float abs;
    float ord;

} Point;


void saisir_point(Point*);
Point* create_point(const char* str, float abs, float ord);
void affiche(const Point *p);
void liberer(Point *p);
void rename_point(Point *p, const char* new_point_name);

int main()
{
    Point *p;
    p = create_point("A123",1.0,2.0);
    affiche((const Point*)p);
    //liberer(p);
    affiche((const Point*)p);

    rename_point(p, "A0");
    affiche((const Point*)p);
    rename_point(p, "Origine");
    affiche((const Point*)p);
    liberer(p);

    int nb_points;
    printf("nb points "); scanf("%d",&nb_points);

    Point *p_array;
    p_array = (Point*) calloc(nb_points, sizeof(Point));
    for(int i = 0; i < nb_points; i++)
    {
        affiche((const Point*) (p_array+i));
    }

    for(int i = 0; i < nb_points; i++)
    {
        saisir_point(p_array+i);
    }

    for(int i = 0; i < nb_points; i++)
    {
        affiche((const Point*) (p_array+i));
    }


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

void rename_point(Point *p, const char* new_point_name)
{
    if(p != NULL)
    {
        p->name = (char*) realloc(p->name, sizeof(new_point_name));
        strcpy(p->name,new_point_name);
    }
}


void saisir_point(Point* p) {
    char libelle[64];
    if(p != NULL)
    {
        printf("Point Label : "); scanf("%s",libelle);
        p->name = (char*) malloc(strlen(libelle));
        strcpy(p->name, libelle);
        printf("Abs :"); scanf("%f",&p->abs);
        printf("Ord :"); scanf("%f",&p->ord);

    }

}

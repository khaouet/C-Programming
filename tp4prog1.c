/**
  * ---------------------------------------------------------------------------
  * @Source file : tp4prog1.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : Structures in C
  * @description : In C, a struct (short for "structure") is a
  *                user-defined data type that allows grouping variables of
  *                different types under one name. It is typically used for
  *                organizing and managing data logically.
  * ---------------------------------------------------------------------------
  */


#include <stdio.h>
#include <stdlib.h>

/**
  A struct declaration defines a new data type.
  the struct keyword is used for it's declaration.
  */

struct Point {
    int x; // X-coordinate structure member
    int y; // Y-coordinate structure member
};

struct Fraction {
    int num;
    int den;
};

struct Cercle {
    struct Point centre;
    float rayon;
};
/**
    TopLeft
    +-------------------+
    |                   |
    |                   |
    +-------------------+
                        ButtomRight
*/

struct Rectangle {
     struct Point  TopLeft;
     struct Point  ButtomRight;
};

struct Date {
        int jour;
        int mois;
        int annee;
};

struct Etudiant {
     unsigned int ncin;
     char nom[64];
     char pnom[128];
     struct Date dnaiss;
     char classe[8];
};

int main()
{
    struct Point p1;            // Define a variable of type Point
    struct Point p2 = {30, 40}; // Initialize p2 with x=30, y=40
    p1.x = 10;                  // Assign values to members
    p1.y = 20;                  // Assign values to members
    /** Members of a struct are accessed using the dot (.) operator
        for regular variables
      */
    printf("x = %d, y = %d\n", p1.x, p1.y);   // Using dot operator
    printf("x = %d, y = %d\n", p2.x, p2.y);   // Using dot operator

    struct Cercle c = { {1, 2}, 0.5};
    printf("le cercle de rayon %.2f et de centre o<%d,%d>\n",c.rayon, c.centre.x, c.centre.y);
    c.rayon*=10;
    c.centre.x = 0;
    c.centre.y = 0;
    printf("le cercle de rayon %.2f et de centre o<%d,%d>\n",c.rayon, c.centre.x, c.centre.y);

    struct Point tab[100];
    tab[0].x = 5;
    tab[0].y = 6;
    tab[1].x = 4;
    tab[1].y = 2;
    return 0;
}

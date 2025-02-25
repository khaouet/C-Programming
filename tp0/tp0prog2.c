/*---------------------------------------------------------------------------
  Source file : tp0prog2.c
  Author      : Khaled HAOUET
  Object      : This program demonstrates arithmetic type usage
                for the C language
-----------------------------------------------------------------------------*/

/* Inclusion of standard libraries */
/* stdio.h is a header file        */
/* stdlib.h is a header file       */

#include <stdio.h>   // standard library for input/output
#include <stdlib.h>  // standard library

/* --------------------------------------------------------------------------
   every C program must provide a main function which is an entry point for
   our program. only one main function must be defined
-----------------------------------------------------------------------------*/

int main()
{
    /* Declaration of character variable */
    char myChar = 'A'; /* char is keyword used to declare a character variable
                          myChar is the name of the declared variable
                          also called the identifier of the variable
                          myChar is Initialized with the literal constant 'A'
                          which designate a character type constant */
    char Color;       /*  Color is the name of the declared variable
                          Color is not Initialized */
    /* print the value of myChar variable                                                                      */
    /* %c is used to format the variable myChar to be interpreted as a Character                               */
    printf("the value of myChar is %c \n", myChar);

    /* print the value of Color variable */
    printf("print of non-initialized variable: his value is not predictable\n");
    printf("the value of Color is %c \n", Color); /* Color is not initialized --> his value is not predictable */

    /* one way to initialize a variable is to use the = operator (assignment operator) */

    Color = 'R' ;
    /* print the value of Color variable */
    printf("print of an initialized variable: his value is predictable\n");

    printf("the value of Color is %c \n", Color); /* Color is initialized --> his value is 'R' */

    /* list of non-initialized character variables declaration separated by a comma*/
    char Shirt_Size, Arith_Operation, Sexe;

    printf("Shirt Size = %c , Arithmetic Operator = %c , Sexe = %c\n", Shirt_Size, Arith_Operation, Sexe );
    /* Initialization of the above non-initialized variable using assignment operator =                       */
    Shirt_Size = 'L';
    Arith_Operation = '/';
    Sexe = 'M';
    printf("Shirt Size = %c , Arithmetic Operator = %c , Sexe = %c\n", Shirt_Size, Arith_Operation, Sexe );

    /* %d is used as a formatter in printf function to interpret a variable as an integer value  */
    //myChar = myChar + 1;
    myChar = 77;
    printf("the value of myChar is %c \n", myChar);
    printf("the value of myChar is %d \n", myChar); /* print the ASCII value of 'A' : 65         */
    printf("Shirt Size = %d , Arithmetic Operator = %d , Sexe = %d\n", Shirt_Size, Arith_Operation, Sexe );

    /* Conclusion : a variable is an entity of a programming language having:
                     - a type
                     - a name : called also identifier
                     - a value
                     - a memory address
                     - a size in bytes
                    a variable may be not initialized */
    printf("type of myChar : char\nname of myChar : myChar\nvalue of myChar : %c\nMemory address of myChar : %p\nSize in byte(s) of myChar : %d",
             myChar, &myChar, sizeof(myChar));


    return 0;
}


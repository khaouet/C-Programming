/**---------------------------------------------------------------------------
  Source file : tp3prog2.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : strings using C language
                - strcat
                - strncat
                - strcpy
                - strncpy
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Pour gérer les paramètres régionaux (accents)

int main()
{
    setlocale(LC_ALL, "");
    char mystr[256]={'\0'};
    char phrase[] = "je suis un étudiant de ISET Rades au Dpt GE";
    puts(mystr);
    puts(phrase);

    strcpy(mystr,"");
    puts(mystr);
    puts("----------------");
    strncpy(mystr,phrase,19);
    puts(mystr);
    strcat(mystr," en génie electrique");
    puts(mystr);
    strcat(mystr," ma classe est L1-GEx");
    puts(mystr);
    strcpy(mystr,phrase);
    puts(mystr);
    puts("----------------");
    strncpy(mystr,phrase,19);
    puts(mystr);
    char str[50] = "Hello ";
    char str2[50] = "World!";
    strcat(str, str2);
    strncat(str, " Goodbye World!", 8);
    puts(str);
    return 0;
}

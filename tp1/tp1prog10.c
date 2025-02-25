#include <stdio.h>
#include <stdlib.h>

/**

    (des-boucles-for)
    Ecrire les programmes qui produisent les affichages suivants:

    1. Avec une boucle for.
        (a) 1 2 3 4 5
        (b) 1
            2
            3
            4
            5

    2. Avec deux boucles for.
        (a) 1
            1 2 3
            2
            1 2 3
            3
            1 2 3
            4
            1 2 3
        (b) 1
            1
            2
            1 2
            3
            1 2 3
            4
            1 2 3 4
        (c) 1
            1
            2
            2 4
            3
            3 6 9
            4
            4 8 12 16

    3. Après avoir déclaré et initialisé une chaîne de caractères à la valeur "abcde",
       écrire les programmes qui parcourent la chaîne de caractères pour donner les affichages suivants.

            (a) 1
                a
                2
                ab
                3
                abc
                4
                abcd
            (b) 1
                e
                2
                ed
                3
                edc
                4
                edcb
            (c) 1
                e
                2
                de
                3
                cde
                4
                bcde

     (des-boucles-while)
     Reprendre l’exercice précédent en utilisant des boucles while
     à la place des boucles for.

*/


int main()
{
    /* Initialisation d'une chaine de caractères */
    const char* str = "abcde";
    /* affichage d'une chaine en utilisant printf */
    printf("%s\n",str);
    printf("%c\n",str[0]);
    printf("%c\n",str[1]);
    printf("%c\n",str[2]);
    printf("%c\n",str[3]);
    printf("%c\n",str[4]);

    return 0;
}

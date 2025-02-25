#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
    RAND_MAX
    C Numerics Pseudo-random number generation
    Defined in header <stdlib.h>

    #define RAND_MAX // implementation defined

    Expands to an integer constant expression equal to the maximum value returned
    by the function rand(). This value is implementation dependent.
    It's guaranteed that this value is at least 32767.

*/



/**
    La fonction rand() renvoit un entier (int) pseudo-al�atoire selon une distribution
    uniforme dans l�intervalle [0, RAND_MAX].
    Ecrire les traitements suivants en faisant varier � votre
    convenance le nombre de valeurs g�n�r�es N en utilisant
    un #define (N = 100, 1000, 10000).
    Commenter les r�sultats observ�s.
    1. Observer des ensembles de valeurs g�n�r�es.
    2. Calculer la r�partition (en pourcentage) des valeurs inf�rieures et sup�rieures � RAND_MAX/2
       (moiti� inf�rieure / moiti� sup�rieure).
    3. Calculer la r�partition (en pourcentage) des valeurs sur les intervalles s�par�s par RAND_MAX/4,
       RAND_MAX/2 et 3*RAND_MAX/4.
    4. Combien de tirages sont n�cessaires pour g�n�rer 5 valeurs de plus dans la moiti� inf�rieure que
       dans la moiti� sup�rieure.
    5. G�n�raliser le traitement pr�c�dent pour exp�rimenter combien de tirages sont n�cessaires pour
       g�n�rer i valeurs de plus dans la moiti� inf�rieure que dans la moiti� sup�rieure avec i = 1, 2, . . . , 10.
    6. Il est classique de faire varier les valeurs g�n�r�es � chaque ex�cution en initialisant la graine
       du g�n�rateur par l�heure du syst�me. Ceci est obtenu gr�ce � l�appel srand(time(NULL)) qui
       utilise la fonction time de la librairie time.h Observer les effets sur les r�sultats des questions
       pr�c�dentes

*/



int main(void)
{
    /**
        example d'utilisation
    */
    srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);

    // roll a 6-sided die 20 times
    for (int n=0; n != 20; ++n) {
        int x = 7;
        while(x > 6)
            x = 1 + rand()/((RAND_MAX + 1u)/6); // Note: 1+rand()%6 is biased
        printf("%d",  x);
    }
}


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
    La fonction rand() renvoit un entier (int) pseudo-aléatoire selon une distribution
    uniforme dans l’intervalle [0, RAND_MAX].
    Ecrire les traitements suivants en faisant varier à votre
    convenance le nombre de valeurs générées N en utilisant
    un #define (N = 100, 1000, 10000).
    Commenter les résultats observés.
    1. Observer des ensembles de valeurs générées.
    2. Calculer la répartition (en pourcentage) des valeurs inférieures et supérieures à RAND_MAX/2
       (moitié inférieure / moitié supérieure).
    3. Calculer la répartition (en pourcentage) des valeurs sur les intervalles séparés par RAND_MAX/4,
       RAND_MAX/2 et 3*RAND_MAX/4.
    4. Combien de tirages sont nécessaires pour générer 5 valeurs de plus dans la moitié inférieure que
       dans la moitié supérieure.
    5. Généraliser le traitement précédent pour expérimenter combien de tirages sont nécessaires pour
       générer i valeurs de plus dans la moitié inférieure que dans la moitié supérieure avec i = 1, 2, . . . , 10.
    6. Il est classique de faire varier les valeurs générées à chaque exécution en initialisant la graine
       du générateur par l’heure du système. Ceci est obtenu grâce à l’appel srand(time(NULL)) qui
       utilise la fonction time de la librairie time.h Observer les effets sur les résultats des questions
       précédentes

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


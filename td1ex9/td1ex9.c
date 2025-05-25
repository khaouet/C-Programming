#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* use of cos */

/**

Exercice

Évaluation d'un Système Électrique:
Le but de ce programme est l’évaluation d’un système électrique
Le programme doit exécuter les étapes suivantes :
1. Saisie des données : Demandez à l'utilisateur d'entrer
    ¤ une valeur entière non signée représentant la tension U (en mV).
    ¤ une valeur entière non signée représentant le courant I (mA)
    ¤ une valeur entière représenant un angle de déphasage phi compris en 0 et 90 en degré

2. Calculer la puissance active P consommée par la charge en Watts
      P = U x I x cos(phi)
      Attention phi doit être converti en randian
      P est une variable à Déclarer
    ¤ Calculer l'énergie consommée W par l’ensemble pendant 24 H en kWh
       W = P x t
       W est une variable à déclarer
    ¤ Calculer le coût journalier de fonctionnement en arrondissant le tarif de la STEG à 300 millimes le kWh
3. Vérification des spécifications :
    ¤ le courant doit être inférieur à 32A, Si ce n'est pas le cas, affichez un message d'erreur le système est surchargé
    ¤ le dephasage doit être compris entre 0 et 90° Si ce n'est pas le cas, affichez un message d'erreur

4. Affichage des résultats :
    ¤ Affichez les valeurs calculées. éventuellement les messages d'érreurs

*/

#define MAX_MILLI_AMPERE    32000 /* 32A */
#define MIN_DEPHASAGE       0     /* 0 degree*/
#define MAX_DEPHASAGE       90    /* 90 degree*/
#define KWH_COST_MILLIMES   300   /* 300 millimes le KWh*/
#define DUREE               24    /* Une journée */

int main()
{
    /** 1. */
    unsigned int U,I,phi;
    double P, W, cost;
    const double PI = acos(-1);

    printf("U (mV) = ");
    scanf("%u",&U);
    printf("I (mA) = ");
    scanf("%u",&I);
    printf("phi(deg) = ");
    scanf("%u",&phi);
    /** 2. */
    /*
        cos is a function that takes a double as parameter in radians
        returns a double : the cosine of this parameter
    */
    /* phi is in degree we must do a conversion between degrees and radians */
    /**
        0 ° --> 0 radians
        phi ° --> x radains
        180° --> PI;
        1 ° --> PI / 180
        phi ° --> phi*PI/180

    */

    P = (U/1000.0) * (I/1000.0) * cos((double)phi*PI/180);
    W = P * DUREE / 1000.0; /* W en KWh*/
    cost = W * KWH_COST_MILLIMES /* cost en millimes*/;
    /** 3. */
    if (phi >= MIN_DEPHASAGE && phi <= MAX_DEPHASAGE)
    {
        if ( I <= MAX_MILLI_AMPERE)
        {
            /** 4 */
            printf("Puissance = %.3lf (W), Energie = %.3lf (kWh), Cost = %lf millimes",P,W, cost );
        }
        else
        {
            /** 3. */
            printf("Surcharge");
        }
    }
    else
    {
        /** 3. */
        printf("Déphasage Incorrect");
    }
    return 0;
}

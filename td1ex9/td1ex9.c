#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* use of cos */

/**

Exercice

�valuation d'un Syst�me �lectrique:
Le but de ce programme est l��valuation d�un syst�me �lectrique
Le programme doit ex�cuter les �tapes suivantes :
1. Saisie des donn�es : Demandez � l'utilisateur d'entrer
    � une valeur enti�re non sign�e repr�sentant la tension U (en mV).
    � une valeur enti�re non sign�e repr�sentant le courant I (mA)
    � une valeur enti�re repr�senant un angle de d�phasage phi compris en 0 et 90 en degr�

2. Calculer la puissance active P consomm�e par la charge en Watts
      P = U x I x cos(phi)
      Attention phi doit �tre converti en randian
      P est une variable � D�clarer
    � Calculer l'�nergie consomm�e W par l�ensemble pendant 24 H en kWh
       W = P x t
       W est une variable � d�clarer
    � Calculer le co�t journalier de fonctionnement en arrondissant le tarif de la STEG � 300 millimes le kWh
3. V�rification des sp�cifications :
    � le courant doit �tre inf�rieur � 32A, Si ce n'est pas le cas, affichez un message d'erreur le syst�me est surcharg�
    � le dephasage doit �tre compris entre 0 et 90� Si ce n'est pas le cas, affichez un message d'erreur

4. Affichage des r�sultats :
    � Affichez les valeurs calcul�es. �ventuellement les messages d'�rreurs

*/

#define MAX_MILLI_AMPERE    32000 /* 32A */
#define MIN_DEPHASAGE       0     /* 0 degree*/
#define MAX_DEPHASAGE       90    /* 90 degree*/
#define KWH_COST_MILLIMES   300   /* 300 millimes le KWh*/
#define DUREE               24    /* Une journ�e */

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
        0 � --> 0 radians
        phi � --> x radains
        180� --> PI;
        1 � --> PI / 180
        phi � --> phi*PI/180

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
        printf("D�phasage Incorrect");
    }
    return 0;
}

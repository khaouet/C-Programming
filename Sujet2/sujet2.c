/**
Sujet2 : Contr�le et simulation d�un moteur �lectrique (variateur de vitesse)
Objectif principal :
D�velopper un programme en langage C pour simuler le fonctionnement d�un moteur
�lectrique contr�l� par un variateur de vitesse, avec des param�tres ajustables
par l�utilisateur.

Description du projet :
Le programme permettra de :
Simulation des param�tres du moteur :
Puissance nominale (en kW).
Tension d�alimentation (en V).
Vitesse maximale (en tr/min).
R�glage de la vitesse :
L�utilisateur pourra simuler un changement de consigne de vitesse 
(en pourcentage de la vitesse maximale).
Le programme affichera la vitesse effective du moteur.
Calcul de la puissance consomm�e :
En fonction de la vitesse r�gl�e et d�un facteur de charge simul� 
(exemple : 70 % de charge � 50 % de vitesse).
Ajout de conditions dynamiques :
Si la vitesse d�passe une certaine limite, afficher un message d�alerte ("Surcharge").
Simuler un arr�t d�urgence si la temp�rature du moteur (g�n�r�e al�atoirement) 
d�passe une valeur critique.
Statistiques d�exploitation (optionnel) :
Calculer l��nergie totale consomm�e sur une p�riode donn�e.

Concepts couverts :
Variables et calculs math�matiques : Manipulation des formules de base 
(Puissance = Tension � Courant, Vitesse = % � Vitesse max).
Conditions et boucles : Gestion des limites, alertes, et ajustements dynamiques.
Modularit� : Organisation du programme en fonctions sp�cifiques (contr�le de vitesse, 
simulation de temp�rature, calcul d��nergie).
Interaction utilisateur : Entr�es pour ajuster les param�tres en temps r�el.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // Initialisation du g�n�rateur de nombres al�atoires

    // D�claration des variables du moteur
    float puissance_nominale = 5.0;  // Puissance nominale en kW
    float tension = 400.0;           // Tension d'alimentation en V
    int vitesse_max = 3000;          // Vitesse maximale en tr/min
    float vitesse_effective = 0;     // Vitesse effective en tr/min
    float facteur_charge = 0.7;     // Facteur de charge (70%)
    float temperature = 0;           // Temp�rature simul�e du moteur en �C
    float pourcentage_vitesse = 0;  // Pourcentage de vitesse r�gl� par l'utilisateur
    float puissance = 0;            // Puissance consomm�e par le moteur
    int temps_utilisation = 0;      // Temps d'utilisation du moteur en secondes
    float energie_totale = 0;       // �nergie totale consomm�e en kWh
    int choix;  // Choix de l'utilisateur pour le menu

    // Boucle principale
    while (1) {
        // Affichage du menu
        printf("\n--- Menu ---\n");
        printf("1. Changer la vitesse du moteur\n");
        printf("2. Afficher les statistiques du moteur\n");
        printf("3. Simuler la temp�rature du moteur\n");
        printf("4. Mettre � jour le temps d'utilisation\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Changer la vitesse du moteur
                printf("Entrez un pourcentage de vitesse (0-100) : ");
                scanf("%f", &pourcentage_vitesse);

                // Validation de l'entr�e
                if (pourcentage_vitesse < 0 || pourcentage_vitesse > 100) {
                    printf("Erreur : Le pourcentage de vitesse doit �tre entre 0 et 100.\n");
                } else {
                    vitesse_effective = (vitesse_max * pourcentage_vitesse) / 100;
                    printf("Vitesse r�gl�e � %.2f %% de la vitesse maximale (%.2f tr/min).\n", pourcentage_vitesse, vitesse_effective);
                }
                break;

            case 2:
                // Afficher les statistiques du moteur
                printf("\n--- Statistiques du Moteur ---\n");
                printf("Puissance nominale : %.2f kW\n", puissance_nominale);
                printf("Tension d'alimentation : %.2f V\n", tension);
                printf("Vitesse maximale : %d tr/min\n", vitesse_max);
                printf("Vitesse effective : %.2f tr/min\n", vitesse_effective);
                printf("Facteur de charge : %.2f %%\n", facteur_charge * 100);
                printf("Temp�rature du moteur : %.2f �C\n", temperature);
                printf("Temps d'utilisation : %d secondes\n", temps_utilisation);
                printf("�nergie totale consomm�e : %.2f kWh\n", energie_totale);
                break;

            case 3:
                // Simuler la temp�rature du moteur
                temperature = rand() % 100 + 20;  // Temp�rature al�atoire entre 20 et 119�C
                printf("Temp�rature simul�e du moteur : %.2f�C\n", temperature);

                // V�rifier les alertes
                if (vitesse_effective > 0.9 * vitesse_max) {
                    printf("\nALERTE : Surcharge, vitesse trop �lev�e!\n");
                }
                if (temperature > 100) {
                    printf("\nALERTE : Temp�rature trop �lev�e ! Arr�t d'urgence du moteur.\n");
                    return 0; // Arr�t d'urgence du moteur
                }
                break;

            case 4:
                // Mettre � jour le temps d'utilisation
                printf("Entrez la dur�e d'utilisation en secondes : ");
                scanf("%d", &temps_utilisation);

                // Calculer l'�nergie consomm�e
                energie_totale += (puissance * temps_utilisation) / 3600;  // kWh = kW * heures
                break;

            case 5:
                // Quitter le programme
                printf("Programme termin�.\n");
                return 0;

            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
        }

        // Calculer la puissance consomm�e
        float vitesse_pourcentage = vitesse_effective / vitesse_max;
        puissance = puissance_nominale * vitesse_pourcentage * facteur_charge;
        printf("Puissance consomm�e par le moteur : %.2f kW\n", puissance);

        // V�rification des alertes apr�s chaque action
        if (vitesse_effective > 0.9 * vitesse_max) {
            printf("\nALERTE : Surcharge, vitesse trop �lev�e!\n");
        }
        if (temperature > 100) {
            printf("\nALERTE : Temp�rature trop �lev�e ! Arr�t d'urgence du moteur.\n");
            return 0; // Arr�t d'urgence du moteur
        }
    }

    return 0;
}

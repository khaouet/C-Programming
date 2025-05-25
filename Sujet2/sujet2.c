/**
Sujet2 : Contrôle et simulation d’un moteur électrique (variateur de vitesse)
Objectif principal :
Développer un programme en langage C pour simuler le fonctionnement d’un moteur
électrique contrôlé par un variateur de vitesse, avec des paramètres ajustables
par l’utilisateur.

Description du projet :
Le programme permettra de :
Simulation des paramètres du moteur :
Puissance nominale (en kW).
Tension d’alimentation (en V).
Vitesse maximale (en tr/min).
Réglage de la vitesse :
L’utilisateur pourra simuler un changement de consigne de vitesse 
(en pourcentage de la vitesse maximale).
Le programme affichera la vitesse effective du moteur.
Calcul de la puissance consommée :
En fonction de la vitesse réglée et d’un facteur de charge simulé 
(exemple : 70 % de charge à 50 % de vitesse).
Ajout de conditions dynamiques :
Si la vitesse dépasse une certaine limite, afficher un message d’alerte ("Surcharge").
Simuler un arrêt d’urgence si la température du moteur (générée aléatoirement) 
dépasse une valeur critique.
Statistiques d’exploitation (optionnel) :
Calculer l’énergie totale consommée sur une période donnée.

Concepts couverts :
Variables et calculs mathématiques : Manipulation des formules de base 
(Puissance = Tension × Courant, Vitesse = % × Vitesse max).
Conditions et boucles : Gestion des limites, alertes, et ajustements dynamiques.
Modularité : Organisation du programme en fonctions spécifiques (contrôle de vitesse, 
simulation de température, calcul d’énergie).
Interaction utilisateur : Entrées pour ajuster les paramètres en temps réel.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // Initialisation du générateur de nombres aléatoires

    // Déclaration des variables du moteur
    float puissance_nominale = 5.0;  // Puissance nominale en kW
    float tension = 400.0;           // Tension d'alimentation en V
    int vitesse_max = 3000;          // Vitesse maximale en tr/min
    float vitesse_effective = 0;     // Vitesse effective en tr/min
    float facteur_charge = 0.7;     // Facteur de charge (70%)
    float temperature = 0;           // Température simulée du moteur en °C
    float pourcentage_vitesse = 0;  // Pourcentage de vitesse réglé par l'utilisateur
    float puissance = 0;            // Puissance consommée par le moteur
    int temps_utilisation = 0;      // Temps d'utilisation du moteur en secondes
    float energie_totale = 0;       // Énergie totale consommée en kWh
    int choix;  // Choix de l'utilisateur pour le menu

    // Boucle principale
    while (1) {
        // Affichage du menu
        printf("\n--- Menu ---\n");
        printf("1. Changer la vitesse du moteur\n");
        printf("2. Afficher les statistiques du moteur\n");
        printf("3. Simuler la température du moteur\n");
        printf("4. Mettre à jour le temps d'utilisation\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Changer la vitesse du moteur
                printf("Entrez un pourcentage de vitesse (0-100) : ");
                scanf("%f", &pourcentage_vitesse);

                // Validation de l'entrée
                if (pourcentage_vitesse < 0 || pourcentage_vitesse > 100) {
                    printf("Erreur : Le pourcentage de vitesse doit être entre 0 et 100.\n");
                } else {
                    vitesse_effective = (vitesse_max * pourcentage_vitesse) / 100;
                    printf("Vitesse réglée à %.2f %% de la vitesse maximale (%.2f tr/min).\n", pourcentage_vitesse, vitesse_effective);
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
                printf("Température du moteur : %.2f °C\n", temperature);
                printf("Temps d'utilisation : %d secondes\n", temps_utilisation);
                printf("Énergie totale consommée : %.2f kWh\n", energie_totale);
                break;

            case 3:
                // Simuler la température du moteur
                temperature = rand() % 100 + 20;  // Température aléatoire entre 20 et 119°C
                printf("Température simulée du moteur : %.2f°C\n", temperature);

                // Vérifier les alertes
                if (vitesse_effective > 0.9 * vitesse_max) {
                    printf("\nALERTE : Surcharge, vitesse trop élevée!\n");
                }
                if (temperature > 100) {
                    printf("\nALERTE : Température trop élevée ! Arrêt d'urgence du moteur.\n");
                    return 0; // Arrêt d'urgence du moteur
                }
                break;

            case 4:
                // Mettre à jour le temps d'utilisation
                printf("Entrez la durée d'utilisation en secondes : ");
                scanf("%d", &temps_utilisation);

                // Calculer l'énergie consommée
                energie_totale += (puissance * temps_utilisation) / 3600;  // kWh = kW * heures
                break;

            case 5:
                // Quitter le programme
                printf("Programme terminé.\n");
                return 0;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        // Calculer la puissance consommée
        float vitesse_pourcentage = vitesse_effective / vitesse_max;
        puissance = puissance_nominale * vitesse_pourcentage * facteur_charge;
        printf("Puissance consommée par le moteur : %.2f kW\n", puissance);

        // Vérification des alertes après chaque action
        if (vitesse_effective > 0.9 * vitesse_max) {
            printf("\nALERTE : Surcharge, vitesse trop élevée!\n");
        }
        if (temperature > 100) {
            printf("\nALERTE : Température trop élevée ! Arrêt d'urgence du moteur.\n");
            return 0; // Arrêt d'urgence du moteur
        }
    }

    return 0;
}

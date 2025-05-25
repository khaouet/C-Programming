/**

Sujet1 : Simulation et contrôle d’un système d’éclairage intelligent
Objectif principal :
Développer un programme en langage C pour simuler et gérer un système d’éclairage automatique
basé sur des capteurs de lumière et de présence.

Description du projet :
Les étudiants doivent programmer un système qui :
Capteur de lumière : Simuler une valeur d'intensité lumineuse extérieure 
(entrée utilisateur ou aléatoire).
Si la lumière extérieure est insuffisante, les lampes s’allument.
Capteur de présence : Détecter la présence ou l’absence d’une personne dans la pièce 
(via une entrée utilisateur ou une simulation aléatoire).
Les lampes ne s’allument que si une personne est détectée et que la lumière extérieure 
est insuffisante.
Gestion manuelle : Permettre à l’utilisateur de forcer l’allumage ou l’extinction 
via une interface en mode console.
Statistiques : Ajouter un compteur pour mesurer la durée d’utilisation des lampes
et calculer l’énergie consommée (en supposant une puissance fixe par lampe).

Concepts couverts :
Structures conditionnelles et boucles : Gestion des états (présence, lumière extérieure).
Entrées et sorties utilisateur : Simulation des capteurs par des entrées clavier.
Utilisation de fonctions : Modularité pour gérer les différentes fonctionnalités (optionnel).
Simulation et calculs : Énergie consommée = Puissance x Temps

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "");
    // Variables du système
    int luminosity = 0;       // Intensité lumineuse extérieure
    int presence = 0;         // Présence (1 = détectée, 0 = absente)
    int lamps_on = 0;         // État des lampes (1 = allumées, 0 = éteintes)
    int manual_control = 0;   // Mode manuel (1 = actif, 0 = inactif)
    int usage_time = 0;       // Temps total d'utilisation des lampes en secondes
    const int power = 60;     // Puissance fixe des lampes en watts
    int choice;               // Choix utilisateur dans le menu

    srand(time(0));           // Initialisation du générateur aléatoire

    time_t start_time, current_time;  // Variables pour gérer le temps réel
    time(&start_time);  // Enregistrer l'heure de début du programme

    // Boucle principale
    while (1) {
        // Affichage du menu
        printf("\n--- Menu ---\n");
        printf("1. Simuler les capteurs\n");
        printf("2. Activer le mode automatique\n");
        printf("3. Activer le mode manuel\n");
        printf("4. Afficher les statistiques\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        // Gestion des choix avec switch-case
        switch (choice) {
            case 1:
                // Simulation des capteurs
                luminosity = rand() % 100; // Luminosité extérieure (0-99)
                presence = rand() % 2;     // Présence (0 ou 1)
                printf("Luminosité extérieure simulée : %d\n", luminosity);
                printf("Présence détectée : %s\n", presence ? "Oui" : "Non");
                break;

            case 2:
                // Mode automatique
                if (!manual_control) {
                    if (presence && luminosity < 50) {
                        lamps_on = 1;
                        printf("Lampes allumées automatiquement (mode automatique).\n");
                    } else {
                        lamps_on = 0;
                        printf("Lampes éteintes automatiquement (mode automatique).\n");
                    }
                } else {
                    printf("Désactivez le mode manuel pour utiliser le mode automatique.\n");
                }
                break;

            case 3:
                // Mode manuel
                manual_control = 1;
                printf("Mode manuel activé.\n");
                printf("1. Allumer les lampes\n2. Éteindre les lampes\nChoix : ");
                int manual_choice;
                scanf("%d", &manual_choice);
                switch (manual_choice) {
                    case 1:
                        lamps_on = 1;
                        printf("Lampes allumées manuellement.\n");
                        break;
                    case 2:
                        lamps_on = 0;
                        printf("Lampes éteintes manuellement.\n");
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
                break;

            case 4:
                // Affichage des statistiques
                printf("\n--- Statistiques ---\n");
                printf("Temps d'utilisation des lampes : %d secondes\n", usage_time);
                printf("Énergie consommée : %.2f Wh\n", (usage_time / 3600.0) * power);
                printf("---------------------\n");
                break;

            case 5:
                // Quitter le programme
                printf("Programme terminé.\n");
                return 0;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        // Mise à jour du temps d'utilisation des lampes
        time(&current_time);  // Récupérer l'heure actuelle
        if (lamps_on) {
            usage_time = (int)difftime(current_time, start_time); // Calculer le temps d'utilisation en secondes
        }

        // Affichage du temps réel écoulé
        printf("Temps écoulé : %d secondes\n", usage_time);
    }

    return 0;
}

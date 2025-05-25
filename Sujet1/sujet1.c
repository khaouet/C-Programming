/**

Sujet1 : Simulation et contr�le d�un syst�me d��clairage intelligent
Objectif principal :
D�velopper un programme en langage C pour simuler et g�rer un syst�me d��clairage automatique
bas� sur des capteurs de lumi�re et de pr�sence.

Description du projet :
Les �tudiants doivent programmer un syst�me qui :
Capteur de lumi�re : Simuler une valeur d'intensit� lumineuse ext�rieure 
(entr�e utilisateur ou al�atoire).
Si la lumi�re ext�rieure est insuffisante, les lampes s�allument.
Capteur de pr�sence : D�tecter la pr�sence ou l�absence d�une personne dans la pi�ce 
(via une entr�e utilisateur ou une simulation al�atoire).
Les lampes ne s�allument que si une personne est d�tect�e et que la lumi�re ext�rieure 
est insuffisante.
Gestion manuelle : Permettre � l�utilisateur de forcer l�allumage ou l�extinction 
via une interface en mode console.
Statistiques : Ajouter un compteur pour mesurer la dur�e d�utilisation des lampes
et calculer l��nergie consomm�e (en supposant une puissance fixe par lampe).

Concepts couverts :
Structures conditionnelles et boucles : Gestion des �tats (pr�sence, lumi�re ext�rieure).
Entr�es et sorties utilisateur : Simulation des capteurs par des entr�es clavier.
Utilisation de fonctions : Modularit� pour g�rer les diff�rentes fonctionnalit�s (optionnel).
Simulation et calculs : �nergie consomm�e = Puissance x Temps

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
    // Variables du syst�me
    int luminosity = 0;       // Intensit� lumineuse ext�rieure
    int presence = 0;         // Pr�sence (1 = d�tect�e, 0 = absente)
    int lamps_on = 0;         // �tat des lampes (1 = allum�es, 0 = �teintes)
    int manual_control = 0;   // Mode manuel (1 = actif, 0 = inactif)
    int usage_time = 0;       // Temps total d'utilisation des lampes en secondes
    const int power = 60;     // Puissance fixe des lampes en watts
    int choice;               // Choix utilisateur dans le menu

    srand(time(0));           // Initialisation du g�n�rateur al�atoire

    time_t start_time, current_time;  // Variables pour g�rer le temps r�el
    time(&start_time);  // Enregistrer l'heure de d�but du programme

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
                luminosity = rand() % 100; // Luminosit� ext�rieure (0-99)
                presence = rand() % 2;     // Pr�sence (0 ou 1)
                printf("Luminosit� ext�rieure simul�e : %d\n", luminosity);
                printf("Pr�sence d�tect�e : %s\n", presence ? "Oui" : "Non");
                break;

            case 2:
                // Mode automatique
                if (!manual_control) {
                    if (presence && luminosity < 50) {
                        lamps_on = 1;
                        printf("Lampes allum�es automatiquement (mode automatique).\n");
                    } else {
                        lamps_on = 0;
                        printf("Lampes �teintes automatiquement (mode automatique).\n");
                    }
                } else {
                    printf("D�sactivez le mode manuel pour utiliser le mode automatique.\n");
                }
                break;

            case 3:
                // Mode manuel
                manual_control = 1;
                printf("Mode manuel activ�.\n");
                printf("1. Allumer les lampes\n2. �teindre les lampes\nChoix : ");
                int manual_choice;
                scanf("%d", &manual_choice);
                switch (manual_choice) {
                    case 1:
                        lamps_on = 1;
                        printf("Lampes allum�es manuellement.\n");
                        break;
                    case 2:
                        lamps_on = 0;
                        printf("Lampes �teintes manuellement.\n");
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
                break;

            case 4:
                // Affichage des statistiques
                printf("\n--- Statistiques ---\n");
                printf("Temps d'utilisation des lampes : %d secondes\n", usage_time);
                printf("�nergie consomm�e : %.2f Wh\n", (usage_time / 3600.0) * power);
                printf("---------------------\n");
                break;

            case 5:
                // Quitter le programme
                printf("Programme termin�.\n");
                return 0;

            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
        }

        // Mise � jour du temps d'utilisation des lampes
        time(&current_time);  // R�cup�rer l'heure actuelle
        if (lamps_on) {
            usage_time = (int)difftime(current_time, start_time); // Calculer le temps d'utilisation en secondes
        }

        // Affichage du temps r�el �coul�
        printf("Temps �coul� : %d secondes\n", usage_time);
    }

    return 0;
}

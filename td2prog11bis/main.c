#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n; /* Taille de la grille n x n */
    unsigned int lim_g = 0;
    unsigned int lim_d;
    unsigned int lim_h = 0;
    unsigned int lim_b;
    unsigned int pos_lig = 0;
    unsigned int pos_col = 0;

    /* Lecture de la taille de la grille */
    printf("n = ");
    scanf("%u", &n);

    lim_d = n - 1;
    lim_b = n - 1;

    /* Parcours de la grille en spirale */
    while (lim_g <= lim_d && lim_h <= lim_b) {
        /* Vers la droite */
        for (pos_col = lim_g; pos_col <= lim_d; pos_col++) {
            printf("d<%u,%u>", pos_lig, pos_col);
        }
        pos_col--; /* Ajuster pour rester dans les limites */
        printf("<%u,%u>\n", pos_lig, pos_col);
        lim_h++; /* Rétrécir la limite haute */

        /* Vers le bas */
        for (pos_lig = lim_h; pos_lig <= lim_b; pos_lig++) {
            printf("b<%u,%u>", pos_lig, pos_col);
        }
        pos_lig--; /* Ajuster pour rester dans les limites */
        printf("<%u,%u>\n", pos_lig, pos_col);
        lim_d--; /* Rétrécir la limite droite */

        /* Vers la gauche */
        if (lim_h <= lim_b) {
            for (pos_col = lim_d; pos_col >= lim_g; pos_col--) {
                printf("g<%u,%u>", pos_lig, pos_col);
                if (pos_col == 0) break; /* Éviter boucle infinie pour unsigned */
            }
            pos_col++; /* Ajuster pour rester dans les limites */
            printf("<%u,%u>\n", pos_lig, pos_col);
            lim_b--; /* Rétrécir la limite basse */
        }

        /* Vers le haut */
        if (lim_g <= lim_d) {
            for (pos_lig = lim_b; pos_lig >= lim_h; pos_lig--) {
                printf("h<%u,%u>", pos_lig, pos_col);
                if (pos_lig == 0) break; /* Éviter boucle infinie pour unsigned */
            }
            pos_lig++; /* Ajuster pour rester dans les limites */
            printf("\n");
            lim_g++; /* Rétrécir la limite gauche */
        }
    }

    /* Afficher le point final */
    printf("A<%u,%u>\n", pos_lig, pos_col);
    return 0;
}

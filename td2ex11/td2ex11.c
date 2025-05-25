#include <stdio.h>

void parcourir_spirale(int n) {
    int grille[n][n];

    // Directions possibles : droite, bas, gauche, haut
    int dx[] = {0, 1, 0, -1}; // Déplacement en x
    int dy[] = {1, 0, -1, 0}; // Déplacement en y
    char* directions[] = {"droite", "bas", "gauche", "haut"};

    // Initialisation des positions et de la direction de départ
    int x = 0, y = 0, dir = 0; // On commence en haut à gauche (D) en allant vers la droite

    // Limites pour restreindre la zone de parcours
    int haut = 0, bas = n - 1, gauche = 0, droite = n - 1;

    printf("Début du parcours en spirale depuis D (0,0) jusqu'à A.\n");

    for (int i = 0; i < n * n; i++) {
        // Afficher les coordonnées et la direction actuelle
        printf("Coordonnées : (%d, %d) - Direction : %s\n", x, y, directions[dir]);

        // Calculer les nouvelles coordonnées
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // Vérifier les limites de la grille
        if (nx < haut || nx > bas || ny < gauche || ny > droite) {
            // Changer de direction
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];

            // Mettre à jour les limites pour maintenir la spirale
            if (dir == 0) haut++;
            else if (dir == 1) droite--;
            else if (dir == 2) bas--;
            else if (dir == 3) gauche++;
        }

        // Déplacement vers les nouvelles coordonnées
        x = nx;
        y = ny;
    }

    printf("Arrivée en A (%d, %d).\n", x, y);
}

int main() {
    int n;

    // Saisie de la taille de la grille
    printf("Entrez la taille de la grille (n) : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("La taille de la grille doit être positive.\n");
        return 1;
    }

    // Parcourir la grille en spirale
    parcourir_spirale(n);

    return 0;
}

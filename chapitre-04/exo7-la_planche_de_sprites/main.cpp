#include <iostream>
#include <vector>

int main() {
    int C = 0;  // Nombre de colonnes
    int R = 0;  // Nombre de lignes
    int W = 0;  // Largeur d'une case (px)
    int H = 0;  // Hauteur d'une case (px)
    int F = 0;  // Nombre de cases à animer
    int D = 0;  // Durée d'animation d'une case (ms)
    int P = 0;  // Plafon (ms)

    int t = 0;  // Temps accumulé depuis la dernère case
    int n = 0;  // Nombre de durrées
    std::vector<int> dt;  // Stocke les durrées

    int avances = 0;  // Nombre total de pas
    int plafonnes = 0;  // Nombre de fois que le plafond a été dépassé

    int x=0, y=0;  // Position de la case animée

    int c = 0;  // Case actuelle sur laquelle on se trouve

    // --- DÉBUT DU PROGRAMME ---

    // Lis les informations initiales requises
    std::cin >> C >> R >> W >> H >> F >> D >> P;

    // Vérifie que F est compris entre 1 et C * R
    if (F < 1 || F > C * R) {
        return -1;
    }

    // Lis le nombre de durrées à enregistrer
    std::cin >> n;

    // Redimensionne le tableau pour stocker le nombre exact de durrées
    dt.resize(n);

    // Boucle principale
    for (int i = 0; i < n; i++) {
        // Lis la durrée actuelle
        std::cin >> dt[i];

        // vérifie si la durrée dépasse le plafond
        if (dt[i] > P) {
            // Rammène la durrée au plafond
            dt[i] = P;

            // Enregistre le dépassement de plafond
            plafonnes++;
        }

        // Ajoute la durrée dt au temps accumulé
        t += dt[i];
        while (t >= D) {
            t -= D;
            c++;
            if (c > (F - 1)) {
                c = 0;
            }
            avances++;
        }

        // Calcule la position de la case
        x = (c % C) * W;
        y = (c / C) * H;

        // Affiche le résultat
        std::cout << c << " " << x << " " << y << " " << W << " " << H << std::endl;
    }

    // Affiche le bilan
    std::cout << "AVANCES " << avances << std::endl;
    std::cout << "PLAFONNES " << plafonnes << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    int C = 0; // Nombre de colonnes
    int R = 0; // Nombre de lignes
    int W = 0; // Largeur d'une case (px)
    int H = 0; // Hauteur d'une case (px)
    int F = 0; // Nombre de cases à animer
    int D = 0; // Durée d'animation d'une case (ms)
    int P = 0; // Plafon (ms)

    int t = 0; // Temps accumulé depuis la dernère case
    int n = 0; // Nombre de durrées
    std::vector<int> dt; // Stocke les durrées

    int avances = 0; // Nombre total de pas
    int plafonnes = 0; // Nombre de fois que le plafond a été dépassé

    int c = 0; // Case actuelle sur laquelle on se trouve

    // Représente les cases animées
    struct cases {
        int c;
        int x;
        int y;
        int w;
        int h;
    };

    // --- DÉBUT DU PROGRAMME ---

    // Lis les informations initiales requises
    std::cin >> C >> R >> W >> H >> F >> D >> P;

    // Vérifie que F est compris entre 1 et C * R
    if (F < 1 || F > C * R) {
        return -1;
    }

    // Stocke les cases animées
    std::vector<cases> cases(F);

    // Initialize le tableau de cases
    for (int i = 0; i < F; i++) {
        cases[i].c = -1;
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
        
        else {
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
            cases[avances].c = c;
            cases[avances].x = (c % C) * W;
            cases[avances].y = (c / C) * H;
            cases[avances].w = W;
            cases[avances].h = H;
        }
    }

    for (int i = 0; i > avances; i++) {
        if (cases[i].c != -1) {
            std::cout << cases[i].c << " "
            << cases[i].x << " "
            << cases[i].y << " "
            << cases[i].w << " "
            << cases[i].h << " " << std::endl;
        }
    }

    return 0;
}

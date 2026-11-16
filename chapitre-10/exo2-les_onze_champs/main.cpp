#include <iostream>
#include <string>
#include <vector>

struct Fichier {
    unsigned int id = 0;
    float x = 0.0f, y = 0.0f;
    float echelle = 0.0f;
    float rotation = 0.0f;
    float opacite = 0.0f;
    bool miroirX = false, miroirY = false;
    int largeur = 0, hauteur = 0;
    bool selectionne = false;
    std::string chemin;
    int octets = 0;

    int position = 0;
    bool saute = false;
    bool ID = false, selected = false, sourcePath = false;
};

int main() {
    int n;
    if (!(std::cin >> n) || n == 0) {
        std::cout << "RESTENT 0\n";
        std::cout << "CHANGES 0\n";
        return 0;
    }

    std::vector<Fichier> fichiers(n);

    int avance = 0;
    int restent = 0;
    int changes = 0;

    for (int i = 0; i < n; ++i) {
        // Ordre exact de l'énoncé : largeur, hauteur, puis selectionne
        std::cin >> fichiers[i].id >> fichiers[i].x >> fichiers[i].y
                 >> fichiers[i].echelle >> fichiers[i].rotation
                 >> fichiers[i].opacite >> fichiers[i].miroirX
                 >> fichiers[i].miroirY >> fichiers[i].largeur
                 >> fichiers[i].hauteur >> fichiers[i].selectionne
                 >> fichiers[i].chemin >> fichiers[i].octets;

        if (fichiers[i].octets == 0) {
            fichiers[i].saute = true;
            avance++;
        } else {
            fichiers[i].position = i + 1 - avance;
            restent++;

            if (fichiers[i].id != 0) {
                changes++;
                fichiers[i].ID = true;
            }
            if (fichiers[i].selectionne) {
                changes++;
                fichiers[i].selected = true;
            }
            if (fichiers[i].chemin != "-") {
                changes++;
                fichiers[i].sourcePath = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        // k vaut i + 1 (numérotation à partir de 1)
        std::cout << "ITEM " << (i + 1);

        if (fichiers[i].saute) {
            std::cout << " SAUTE\n";
        } else {
            std::cout << " " << fichiers[i].position;

            if (!fichiers[i].ID && !fichiers[i].selected && !fichiers[i].sourcePath) {
                std::cout << " AUCUN";
            } else {
                if (fichiers[i].ID) {
                    std::cout << " id";
                }
                if (fichiers[i].selected) {
                    std::cout << " selected";
                }
                if (fichiers[i].sourcePath) {
                    std::cout << " sourcePath";
                }
            }
            std::cout << "\n";
        }
    }

    std::cout << "RESTENT " << restent << "\n";
    std::cout << "CHANGES " << changes << "\n";

    return 0;
}

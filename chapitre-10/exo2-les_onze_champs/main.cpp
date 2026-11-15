#include <iostream>
#include <vector>

struct Fichier {
    uint id;
    float x, y;
    float echelle;
    float rotation;
    float opacite;
    bool mirroirX, mirroirY;
    bool selectionne;
    int largeur, hauteur;
    std::string chemin;
    int octets;

    int position;

    bool saute;

    bool id, selected, sourcePath;
};

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "RESTENT 0" << std::endl;
        std::cout << "CHANGES 0" << std::endl;
        return 0;
    }

    std::vector<Fichier> fichiers(n);

    int avance = 0;
    int restent = 0;
    int changes = 0;

    for(int i = 0; i < n; ++i) {
        std::cin >> fichiers[i].id >> fichiers[i].x >> fichiers[i].y
                 >> fichiers[i].echelle >> fichiers[i].rotation
                 >> fichiers[i].opacite >> fichiers[i].mirroirX
                 >> fichiers[i].mirroirY >> fichiers[i].selectionne
                 >> fichiers[i].largeur >> fichiers[i].hauteur
                 >> fichiers[i].chemin >> fichiers[i].octets;

        if (fichiers[i].id != 0) {
            changes++;
            fichiers[i].id = true;
        }
        if (fichiers[i].selected != 0) {
            changes++;
            fichiers[i].selected = true;
        }
        if (fichiers[i].chemin != "-") {
            changes++;
            fichiers[i].sourcePath = true;
        }

        if (fichiers[i].octets == 0) {
            fichiers[i].saute = true;
            avance++;
        } else {
            fichiers[i].position = i + 1 - avance;
        }

        if (!fichiers[i].saute) {
            restent++;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << "ITEM " << fichiers[i].id << " " << fichiers[i].position;
        if (fichiers[i].saute) {
            std::cout << " SAUTE";
        } else {
            if (fichiers[i].id) {
                std::cout << " id";
            }
            if (fichiers[i].selected) {
                std::cout << " selected";
            }
            if (fichiers[i].sourcePath) {
                std::cout << " sourcePath";
            }
        }
    }
    std::cout << "RESTENT " << restent << std::endl;
    std::cout << "CHANGES " << changes << std::endl;

    return 0;
}

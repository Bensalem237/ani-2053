#include <iostream>
#include <vector>
#include <string>

int main() {
    // Optimisation des flux d'E/S pour éviter tout problème de format
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v, n;
    int xe = 0, xi = 0;
    int sautsE = 0, sautsI = 0, manques = 0;
    bool isSpacePressed = false;
    bool isRightPressed = false;
    bool isLeftPressed  = false;

    if (!(std::cin >> v >> n)) return 0;

    std::vector<int> final_xe(n);
    std::vector<int> final_xi(n);

    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;

        // On mémorise si un +SPACE s'est produit au cours de cette image
        bool spaceWasTriggeredThisFrame = false;

        for (int j = 0; j < k; j++) {
            std::string ev;
            std::cin >> ev;

            // 1. Gestion des Événements
            if (ev == "+SPACE") {
                sautsE++; // Toujours compté par événement (même si répété)
                isSpacePressed = true;
                spaceWasTriggeredThisFrame = true;
            } else if (ev == "-SPACE") {
                isSpacePressed = false;
            } else if (ev == "+LEFT") {
                xe -= v;
                isLeftPressed = true;
            } else if (ev == "-LEFT") {
                isLeftPressed = false;
            } else if (ev == "+RIGHT") {
                xe += v;
                isRightPressed = true;
            } else if (ev == "-RIGHT") {
                isRightPressed = false;
            }
            // Tout autre événement non mentionné est ignoré par le if/else
        }

        // 2. Gestion de l'Interrogation (à la fin de l'image)
        if (isSpacePressed) {
            sautsI++;
        }
        if (isLeftPressed) {
            xi -= v;
        }
        if (isRightPressed) {
            xi += v;
        }

        // 3. Calcul des MANQUES pour l'image courante
        // Si +SPACE a eu lieu mais que SPACE est relâchée à la fin de l'image
        if (spaceWasTriggeredThisFrame && !isSpacePressed) {
            manques++;
        }

        // Enregistrement des états
        final_xe[i] = xe;
        final_xi[i] = xi;
    }

    // 4. Affichage strict selon le format demandé
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << final_xe[i] << " " << final_xi[i] << "\n";
    }

    std::cout << "SAUTS EVENEMENTS " << sautsE << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsI << "\n";
    std::cout << "MANQUES " << manques << "\n";

    return 0;
}

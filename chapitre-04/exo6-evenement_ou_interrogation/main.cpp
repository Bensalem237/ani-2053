#include <iostream>
#include <vector>
#include <string>

int main() {
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

        bool spaceWasTriggeredThisFrame = false;

        for (int j = 0; j < k; j++) {
            std::string ev;
            std::cin >> ev;

            if (ev == "+SPACE") {
                sautsE++;
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
        }

        if (isSpacePressed) {
            sautsI++;
        }
        if (isLeftPressed) {
            xi -= v;
        }
        if (isRightPressed) {
            xi += v;
        }

        if (spaceWasTriggeredThisFrame && !isSpacePressed) {
            manques++;
        }

        final_xe[i] = xe;
        final_xi[i] = xi;
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << final_xe[i] << " " << final_xi[i] << "\n";
    }

    std::cout << "SAUTS EVENEMENTS " << sautsE << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsI << "\n";
    std::cout << "MANQUES " << manques << "\n";

    return 0;
}

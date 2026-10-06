#include <iostream>
#include <vector>
#include <string>

int main() {
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

        bool spacePressedThisFrame = false;
        bool leftPressedThisFrame  = false;
        bool rightPressedThisFrame = false;

        for (int j = 0; j < k; j++) {
            std::string ev;
            std::cin >> ev;

            if (ev == "+SPACE") {
                if (isSpacePressed) {
                    manques++;
                } else {
                    sautsE++;
                    isSpacePressed = true;
                    spacePressedThisFrame = true;
                }
            } else if (ev == "-SPACE") {
                if (!isSpacePressed) {
                    manques++;
                } else {
                    if (spacePressedThisFrame) {
                        manques++;
                    }
                    isSpacePressed = false;
                }
            }

            if (ev == "+LEFT") {
                if (isLeftPressed) {
                    manques++;
                } else {
                    xe -= v;
                    isLeftPressed = true;
                    leftPressedThisFrame = true;
                }
            } else if (ev == "-LEFT") {
                if (!isLeftPressed) {
                    manques++;
                } else {
                    if (leftPressedThisFrame) {
                        manques++;
                    }
                    isLeftPressed = false;
                }
            }

            if (ev == "+RIGHT") {
                if (isRightPressed) {
                    manques++;
                } else {
                    xe += v;
                    isRightPressed = true;
                    rightPressedThisFrame = true;
                }
            } else if (ev == "-RIGHT") {
                if (!isRightPressed) {
                    manques++;
                } else {
                    if (rightPressedThisFrame) {
                        manques++;
                    }
                    isRightPressed = false;
                }
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

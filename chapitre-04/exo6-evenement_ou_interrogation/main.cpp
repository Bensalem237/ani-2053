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

    struct image {
        int k;
        int actualxe, actualxi;
        std::vector<std::string> ek;
    };

    if (!(std::cin >> v >> n)) return 0;

    std::vector<image> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].k;
        arr[i].ek.resize(arr[i].k);

        bool spacePressedThisFrame = false;
        bool leftPressedThisFrame  = false;
        bool rightPressedThisFrame = false;

        for (int j = 0; j < arr[i].k; j++) {
            std::cin >> arr[i].ek[j];
            std::string ev = arr[i].ek[j];

            if (ev == "+SPACE") {
                sautsE++;
                isSpacePressed = true;
                spacePressedThisFrame = true;
            } else if (ev == "-SPACE") {
                if (!isSpacePressed) {
                    manques++;
                } else if (spacePressedThisFrame) {
                    manques++;
                }
                isSpacePressed = false;
            }

            if (ev == "+LEFT") {
                xe -= v;
                isLeftPressed = true;
                leftPressedThisFrame = true;
            } else if (ev == "-LEFT") {
                if (!isLeftPressed) {
                    manques++;
                } else if (leftPressedThisFrame) {
                    manques++;
                }
                isLeftPressed = false;
            }

            if (ev == "+RIGHT") {
                xe += v;
                isRightPressed = true;
                rightPressedThisFrame = true;
            } else if (ev == "-RIGHT") {
                if (!isRightPressed) {
                    manques++;
                } else if (rightPressedThisFrame) {
                    manques++;
                }
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

        arr[i].actualxe = xe;
        arr[i].actualxi = xi;
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " "
                  << arr[i].actualxe << " "
                  << arr[i].actualxi << std::endl;
    }

    std::cout << "SAUTS EVENEMENTS " << sautsE << std::endl;
    std::cout << "SAUTS INTERROGATION " << sautsI << std::endl;
    std::cout << "MANQUES " << manques << std::endl;

    return 0;
}

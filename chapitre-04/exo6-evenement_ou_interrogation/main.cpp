#include <iostream>

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
        std::string ek[];
    };

    std::cin >> v >> n;

    image arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].k;
        if (arr[i].k == 0) {
            if (isSpacePressed) sautsI++;
            else manques++;
            if (isLeftPressed)  xi -= v;
            else manques++;
            if (isRightPressed) xi += v;
            else manques++;
        } else {
            for (int j = 0; j < arr[i].k; j++) {
                std::cin >> arr[i].ek[j];
                if (arr[i].ek[j] == "+SPACE") {
                    sautsE++;
                    sautsI++;
                    isSpacePressed = true;
                } else if (arr[i].ek[j] == "-SPACE") {
                    isSpacePressed = false;
                }
                if (arr[i].ek[j] == "+LEFT") {
                    xe -= v;
                    xi -= v;
                    isLeftPressed = true;
                    arr[i].actualxe = xe;
                    arr[i].actualxi = xi;
                } else if (arr[i].ek[j] == "-LEFT") {
                    isLeftPressed = false;
                }
                if (arr[i].ek[j] == "+RIGHT") {
                    xe += v;
                    xi += v;
                    isRightPressed = true;
                    arr[i].actualxe = xe;
                    arr[i].actualxi = xi;
                } else if (arr[i].ek[j] == "-RIGHT") {
                    isRightPressed = false;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << i << " "
        << arr[i].actualxe << " "
        << arr[i].actualxi <<std::endl;
    }

    std::cout << "SAUTS EVENEMENTS " << sautsE << std::endl;
    std::cout << "SAUTS INTERROGATION " << sautsI << std::endl;
    std::cout << "MANQUES " << manques << std::endl;

    return 0;
}

#include <iostream>
#include <cmath>

int main() {
    int N;
    const double pi = 3.141592653589793;
    double g;
    int visibles = 0;
    int refuses = 0;

    struct cercle {
        int r;
        int n;
        int ecart;
        int zoom;
        bool refuse = false;
        bool jamais = false;
        bool visible = false;
    };

    std::cin >> N;

    cercle arr[N];

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i].r >> arr[i].n;

        if (arr[i].n < 3) {
            arr[i].refuse = true;
        } else {
            g = arr[i].r * (1 - std::cos(pi / arr[i].n));
            arr[i].ecart = static_cast<int>(std::floor(g * 1000));

            if (g == 0) {
                arr[i].jamais = true;
            } else {
                arr[i].zoom = static_cast<int>(std::ceil(100 / g));
            }

            if (arr[i].zoom <= 100) {
                arr[i].visible = true;
            } else {
                arr[i].visible = false;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << arr[i].r << " " << arr[i].n << " ";
        if (!arr[i].refuse) {
            std::cout << arr[i].ecart << " ";
            if (!arr[i].jamais) {
                std::cout << arr[i].zoom << " ";
                if (arr[i].visible) {
                    std::cout << "VISIBLE" << std::endl;
                    visibles++;
                } else {
                    std::cout << "INVISIBLE" << std::endl;
                }
            } else if (arr[i].jamais) {
                std::cout << "JAMAIS" <<std::endl;
            }
        } else {
            std::cout << "REFUSE" << std::endl;
            refuses++;
        }
    }
    std::cout << "VISIBLES " << visibles <<std::endl;
    std::cout << "REFUSES " << refuses <<std::endl;

    return 0;
}

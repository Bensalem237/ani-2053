#include <iostream>

int main() {
    int N = 0, i = 0;

    struct primitive {
        std::string forme;
        int sommets;
        int nbFormes;
        int sommetsRestants;
        bool refus;
    };

    primitive arr[N];

    struct bilan {
        int points;
        int segments;
        int triangles;
        int refuses;
    };

    bilan total = {0, 0, 0, 0};

    std::cin >> N;

    for (i = 0; i < N; i++) {
        std::cin >> arr[i].forme >> arr[i].sommets;
    }

    for (i = 0; i < N; i++) {
        arr[i].refus = false;
        if (arr[i].forme == "POINTS") {
            arr[i].nbFormes = arr[i].sommets;
            arr[i].sommetsRestants = 0;
            total.points = arr[i].sommets;
        } else if (arr[i].forme == "LINES") {
            arr[i].nbFormes = arr[i].sommets / 2;
            arr[i].sommetsRestants = arr[i].sommets % 2;
            total.segments = arr[i].nbFormes;
        } else if (arr[i].forme == "LINE_STRIP") {
            if (arr[i].sommets < 2) {
                arr[i].nbFormes = 0;
                arr[i].sommetsRestants = arr[i].sommets;
            } else {
                arr[i].nbFormes = arr[i].sommets - 1;
                arr[i].sommetsRestants = 0;
            }
            total.segments = arr[i].nbFormes;
        } else if (arr[i].forme == "TRIANGLES") {
            arr[i].nbFormes = arr[i].sommets / 3;
            arr[i].sommetsRestants = arr[i].sommets % 3;
            total.triangles = arr[i].nbFormes;
        } else if (arr[i].forme == "TRIANGLE STRIP" || arr[i].forme == "TRIANGLE_FAN") {
            if (arr[i].sommets < 3) {
                arr[i].nbFormes = 0;
                arr[i].sommetsRestants = arr[i].sommets;
            } else {
                arr[i].nbFormes = arr[i].sommets - 2;
                arr[i].sommetsRestants = 0;
            }
            total.triangles = arr[i].nbFormes;
        } else {
            arr[i].refus = true;
            total.refuses++;
        }
    }

    for (i = 0; i < N; i++) {
        std::cout << arr[i].forme << " " << arr[i].sommets << " " << arr[i].nbFormes << " " << arr[i].sommetsRestants;
        if (arr[i].refus) {
            std::cout << " REFUS";
        }
        std::cout << std::endl;
    }

    std::cout << "POINTS " << total.points << std::endl;
    std::cout << "LINES " << total.segments << std::endl;
    std::cout << "TRIANGLES " << total.triangles << std::endl;
    std::cout << "REFUSES " << total.refuses << std::endl;

    return 0;
}

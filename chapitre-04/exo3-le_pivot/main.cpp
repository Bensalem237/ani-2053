#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int n;
    int refuses = 0;

    struct form {
        std::string nom;
        int w, h;
        int px, py;
        int ox, oy;
        int sx, sy;
        int angle;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        int minx, miny, maxx, maxy;
        bool refuse = false;
    };

    std::cin >> n;

    form arr[n];

    for (int i = 0; i < n; i++) {
        std::cin
        >> arr[i].nom
        >> arr[i].w
        >> arr[i].h
        >> arr[i].px
        >> arr[i].py
        >> arr[i].ox
        >> arr[i].oy
        >> arr[i].sx
        >> arr[i].sy
        >> arr[i].angle;
    }

    for (int i = 0; i < n; i++) {
        int localX1, localY1, localX2, localY2, localX3,
        localY3, localX4, localY4;

        int aX1, aY1, aX2, aY2, aX3, aY3, aX4, aY4;

        int rX1, rY1, rX2, rY2, rX3, rY3, rX4, rY4;

        int norm = ((arr[i].angle % 360) + 360) % 360;

        int c = 0, s = 0;
        switch (norm) {
            case 0:
                c = 1;
                s = 0;
                break;
            case 90:
                c = 0;
                s = 1;
                break;
            case 180:
                c = -1;
                s = 0;
                break;
            case 270:
                c = 0;
                s = -1;
                break;
            default:
                arr[i].refuse = true;
                break;
        }

        if (arr[i].refuse) {
            continue;
        }

        localX1 = 0;
        localY1 = 0;
        localX2 = arr[i].w;
        localY2 = 0;
        localX3 = arr[i].w;
        localY3 = arr[i].h;
        localX4 = 0;
        localY4 = arr[i].h;

        aX1 = (localX1 - arr[i].ox) * arr[i].sx;
        aY1 = (localY1 - arr[i].oy) * arr[i].sy;
        aX2 = (localX2 - arr[i].ox) * arr[i].sx;
        aY2 = (localY2 - arr[i].oy) * arr[i].sy;
        aX3 = (localX3 - arr[i].ox) * arr[i].sx;
        aY3 = (localY3 - arr[i].oy) * arr[i].sy;
        aX4 = (localX4 - arr[i].ox) * arr[i].sx;
        aY4 = (localY4 - arr[i].oy) * arr[i].sy;

        rX1 = aX1 * c - aY1 * s;
        rY1 = aX1 * s + aY1 * c;
        rX2 = aX2 * c - aY2 * s;
        rY2 = aX2 * s + aY2 * c;
        rX3 = aX3 * c - aY3 * s;
        rY3 = aX3 * s + aY3 * c;
        rX4 = aX4 * c - aY4 * s;
        rY4 = aX4 * s + aY4 * c;

        arr[i].x1 = rX1 + arr[i].px;
        arr[i].y1 = rY1 + arr[i].py;
        arr[i].x2 = rX2 + arr[i].px;
        arr[i].y2 = rY2 + arr[i].py;
        arr[i].x3 = rX3 + arr[i].px;
        arr[i].y3 = rY3 + arr[i].py;
        arr[i].x4 = rX4 + arr[i].px;
        arr[i].y4 = rY4 + arr[i].py;

        arr[i].minx = std::min({arr[i].x1, arr[i].x2, arr[i].x3, arr[i].x4});
        arr[i].miny = std::min({arr[i].y1, arr[i].y2, arr[i].y3, arr[i].y4});
        arr[i].maxx = std::max({arr[i].x1, arr[i].x2, arr[i].x3, arr[i].x4});
        arr[i].maxy = std::max({arr[i].y1, arr[i].y2, arr[i].y3, arr[i].y4});
    }

    for (int i = 0; i < n; i++) {
        if (!arr[i].refuse) {
            std::cout
            << arr[i].nom << " COINS "
            << arr[i].x1 << " " << arr[i].y1 << " "
            << arr[i].x2 << " " << arr[i].y2 << " "
            << arr[i].x3 << " " << arr[i].y3 << " "
            << arr[i].x4 << " " << arr[i].y4 << std::endl;
            std::cout
            << arr[i].nom << " BOITE "
            << arr[i].minx << " " << arr[i].miny << " "
            << arr[i].maxx << " " << arr[i].maxy << std::endl;
        } else {
            std::cout << arr[i].nom << " ANGLE REFUSE" << std::endl;
            refuses++;
        }
    }

    std::cout << "REFUSES " << refuses << std::endl;

    return 0;
}

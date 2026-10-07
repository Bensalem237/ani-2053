#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

struct ObjetMonde {
    std::string nom;
    int x;
    int y;
    int angle;
    int echelle;
    int niveau;
};

int normaliserAngle(int angle) {
    int a = angle % 360;
    if (a < 0) {
        a += 360;
    }
    return a;
}

int main() {

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<std::string> ordreLecture(n);
    std::unordered_map<std::string, ObjetMonde> tableObjets;
    int profondeurMaximale = 0;

    for (int i = 0; i < n; i++) {
        std::string nom, parent;
        int tx, ty, anglePropre, echellePropre;
        
        std::cin >> nom >> parent >> tx >> ty >> anglePropre >> echellePropre;
        ordreLecture[i] = nom;

        ObjetMonde obj;
        obj.nom = nom;

        if (parent == "-") {
            obj.x = tx;
            obj.y = ty;
            obj.angle = normaliserAngle(anglePropre);
            obj.echelle = echellePropre;
            obj.niveau = 1;
        } else {
            const ObjetMonde& p = tableObjets[parent];

            int ax = tx * p.echelle;
            int ay = ty * p.echelle;

            int rx = 0;
            int ry = 0;
            int pAngle = p.angle;

            if (pAngle == 0) {
                rx = ax;
                ry = ay;
            } else if (pAngle == 90) {
                rx = -ay;
                ry = ax;
            } else if (pAngle == 180) {
                rx = -ax;
                ry = -ay;
            } else if (pAngle == 270) {
                rx = ay;
                ry = -ax;
            }

            obj.x = p.x + rx;
            obj.y = p.y + ry;
            obj.angle = normaliserAngle(p.angle + anglePropre);
            obj.echelle = p.echelle * echellePropre;
            obj.niveau = p.niveau + 1;
        }

        if (obj.niveau > profondeurMaximale) {
            profondeurMaximale = obj.niveau;
        }

        tableObjets[nom] = obj;
    }

    for (int i = 0; i < n; i++) {
        const ObjetMonde& obj = tableObjets[ordreLecture[i]];
        std::cout << obj.nom << " "
                  << obj.x << " "
                  << obj.y << " "
                  << obj.angle << " "
                  << obj.echelle << "\n";
    }

    std::cout << "PROFONDEUR " << profondeurMaximale << "\n";

    return 0;
}

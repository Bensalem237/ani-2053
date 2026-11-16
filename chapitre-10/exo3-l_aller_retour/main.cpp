#include <cstdio>
#include <iostream>
#include <string>

struct vec2d {
    double x = 0.0;
    double y = 0.0;
};

vec2d vers_monde(vec2d centre, vec2d pixel, double zoom, double W, double H) {
    return {
        centre.x + (pixel.x - W / 2.0) / zoom,
        centre.y + (pixel.y - H / 2.0) / zoom
    };
}

vec2d vers_pixel(vec2d centre, vec2d monde, double zoom, double W, double H) {
    return {
        (monde.x - centre.x) * zoom + W / 2.0,
        (monde.y - centre.y) * zoom + H / 2.0
    };
}

void deplacer(vec2d &centre, double zoom, double dx, double dy) {
    centre.x -= dx / zoom;
    centre.y -= dy / zoom;
}

void zoomer(vec2d &centre, double &zoom, double facteur, vec2d pixel, double W, double H) {
    vec2d avant = vers_monde(centre, pixel, zoom, W, H);

    zoom *= facteur;
    if (zoom < 0.02) {
        zoom = 0.02;
    }
    if (zoom > 64.0) {
        zoom = 64.0;
    }

    centre.x = avant.x - (pixel.x - W / 2.0) / zoom;
    centre.y = avant.y - (pixel.y - H / 2.0) / zoom;
}

double grille(double zoom, double minPixels) {
    if (minPixels <= 0.0 || zoom <= 0.0) {
        return 1.0;
    }
    double s = 1.0;
    while (s * zoom < minPixels) {
        s *= 2.0;
    }
    while (s * 0.5 * zoom >= minPixels && s > 0.0) {
        s *= 0.5;
    }
    return s;
}

void reinitialiser(vec2d &centre, double &zoom) {
    centre = {0.0, 0.0};
    zoom = 1.0;
}

double a_zero(double v) {
    if (v > -0.005 && v < 0.005) {
        return 0.0;
    }
    return v;
}

int main() {
    double W = 0.0, H = 0.0;
    if (!(std::cin >> W >> H)) {
        return 0;
    }

    vec2d centre = {0.0, 0.0};
    double zoom = 1.0;

    std::string commande;
    while (std::cin >> commande) {
        if (commande == "VERS_MONDE") {
            double px, py;
            if (std::cin >> px >> py) {
                vec2d m = vers_monde(centre, {px, py}, zoom, W, H);
                std::printf("MONDE %.2f %.2f\n", a_zero(m.x), a_zero(m.y));
            }
        } else if (commande == "VERS_PIXEL") {
            double mx, my;
            if (std::cin >> mx >> my) {
                vec2d p = vers_pixel(centre, {mx, my}, zoom, W, H);
                std::printf("PIXEL %.2f %.2f\n", a_zero(p.x), a_zero(p.y));
            }
        } else if (commande == "ZOOM") {
            double f, px, py;
            if (std::cin >> f >> px >> py) {
                zoomer(centre, zoom, f, {px, py}, W, H);
            }
        } else if (commande == "DEPLACE") {
            double dx, dy;
            if (std::cin >> dx >> dy) {
                deplacer(centre, zoom, dx, dy);
            }
        } else if (commande == "GRILLE") {
            double m;
            if (std::cin >> m) {
                double s = grille(zoom, m);
                std::printf("GRILLE %.6f\n", s);
            }
        } else if (commande == "ORIGINE") {
            reinitialiser(centre, zoom);
        }
    }

    std::printf("CENTRE %.2f %.2f\n", a_zero(centre.x), a_zero(centre.y));
    std::printf("ZOOM %.2f\n", a_zero(zoom));

    return 0;
}

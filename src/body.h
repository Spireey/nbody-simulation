#ifndef BODY_H
#define BODY_H

#include <SFML/Graphics.hpp>

class body {
public:
    double mass;
    double radius;
    double x, y; // Position
    double vx, vy; // Velocity
    double ax, ay; // Acceleration
    sf::Color color;
    body(double m, double r, double x_pos, double y_pos, double vx_val = 0, double vy_val = 0, sf::Color col = sf::Color::White)
        : mass(m), radius(r), x(x_pos), y(y_pos), vx(vx_val), vy(vy_val), ax(0), ay(0), color(col) {}
};


#endif //BODY_H

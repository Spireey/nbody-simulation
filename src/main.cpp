#include <iostream>
#include <SFML/Graphics.hpp>
#include "body.h"

#define width 800
#define height 600
#define scaling_factor 200

void renderShapes(sf::RenderWindow & window, const std::vector<body>& bodies) {
    for (const auto& body : bodies) {
        sf::CircleShape shape(body.radius / scaling_factor);
        shape.setFillColor(body.color);
        auto x = static_cast<float>(body.x / scaling_factor);
        auto y = static_cast<float>(body.y / scaling_factor);
        shape.setPosition({x + width / 2, y + height / 2}); // Center the circle at the body's position
        window.draw(shape);
    }
}

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({width, height}), "SFML Window");
    window.setFramerateLimit(60);

    // Initialize a simple body object
    const body earth{5.976e24, 6378, 0, 0, 0, 29780, sf::Color::Blue};
    const body moon{7.34767309e22, 1737, 384400 - 360000, 0, 0, 1022, sf::Color::White};
    std::vector<body> bodies = {earth, moon};
    const std::vector<sf::Color> colors = {sf::Color::Blue, sf::Color::White};

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();

        // Render the body as a circle shape
        renderShapes(window, bodies);
        window.display();
    }
}

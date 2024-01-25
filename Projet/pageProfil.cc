#include "pageProfil.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void pageProfil(){
    sf::RenderWindow pageProfil(sf::VideoMode(1000, 800), "Espace personnel");
    pageProfil.setPosition(sf::Vector2i(500, 100));
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }

    while (pageProfil.isOpen()) {
        sf::Event event;
        while (pageProfil.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pageProfil.close();
            }
        }
        pageProfil.clear(sf::Color(250, 250, 250));

        pageProfil.display();
    }

}
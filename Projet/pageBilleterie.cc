#include "pageBilleterie.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


void pageBilleterie(){
    sf::RenderWindow pageEvenements(sf::VideoMode(1000, 800), "La billeterie officielle des JO de Paris 2024");
    pageEvenements.setPosition(sf::Vector2i(500, 100));

    // image
    sf::Texture texture;
    if (!texture.loadFromFile("../images/billeterie.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit(-1);
    }
    sf::Sprite imagePageBilleterie;
    imagePageBilleterie.setTexture(texture);
    sf::FloatRect spriteSize = imagePageBilleterie.getGlobalBounds();
    texture.setSmooth(true);
    // centre l'image
    imagePageBilleterie.setOrigin(static_cast<float>(spriteSize.width / 2.), static_cast<float>(spriteSize.height / 2.));
    imagePageBilleterie.setPosition(pageEvenements.getSize().x / 1.8, 100);
    imagePageBilleterie.setScale(0.8, 0.8);

    while(pageEvenements.isOpen()){
        sf::Event event;
        while(pageEvenements.pollEvent(event)){
            if(event.type == sf::Event::Closed) pageEvenements.close();
        }
        pageEvenements.clear(sf::Color(250, 250, 250));
        //affichage des elements
        pageEvenements.draw(imagePageBilleterie);

        pageEvenements.display();
    }

}

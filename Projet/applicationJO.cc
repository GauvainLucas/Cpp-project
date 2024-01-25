#include <SFML/Graphics.hpp>
#include <iostream>
#include "applicationJO.hh"
#include "pageEvenements.hpp"
#include "pageBilleterie.hpp"



UtilisateurVIP johnDoe("Doe", "John", "", "", "jdoe", "1234", "VIP");
UtilisateurPublic janeDoe("Doe", "Jane", "", "", "jane", "1234", "Public");
Utilisateur *utilisateurCourant = &janeDoe;
int main() {

    sf::RenderWindow mainWindow(sf::VideoMode(1000, 800), "Application JO");
    mainWindow.setPosition(sf::Vector2i(500, 100));
    // Create texture from PNG file
    sf::Texture texture;
    if (!texture.loadFromFile("../images/logoJO.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit (-1);
    }
    // Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
    texture.setSmooth(true);
    // Create the logoJO and apply the texture
    sf::Sprite logoJO;
    logoJO.setTexture(texture);
    sf::FloatRect spriteSize = logoJO.getGlobalBounds();
    logoJO.setOrigin(static_cast<float>(spriteSize.width / 2.), static_cast<float>(spriteSize.height / 2.));
    logoJO.setScale(0.25, 0.25);

    sf::Text textBienvenue;
    sf::Text textUtilisateur;
    sf::Text textVoirEvenements;
    sf::Text textAcheterTicket;
    sf::Text textVoirActualites;
    sf::Text textFooter;
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit (-1);
    }
    // select the font
    textBienvenue.setFont(font); // font is a sf::Font
    textUtilisateur.setFont(font); // font is a sf::Font
    textVoirEvenements.setFont(font); // font is a sf::Font
    textAcheterTicket.setFont(font); // font is a sf::Font
    textVoirActualites.setFont(font); // font is a sf::Font
    textFooter.setFont(font); // font is a sf::Font

    // set the string to display
    textBienvenue.setString("Bienvenue sur l'application des JO de Paris 2024 !");
    textUtilisateur.setString(utilisateurCourant->getPrenom() + " " + utilisateurCourant->getNom() + "\n" + utilisateurCourant->getType());
    textVoirEvenements.setString("Voir les evenements");
    textAcheterTicket.setString("Acceder a la billeterie");
    textVoirActualites.setString("Dernieres actualites");
    textFooter.setString("Paris 2024 - Designed by Lucas Gauvain & Jacky Chui - All rights reserved");
    // set the character size
    textBienvenue.setCharacterSize(24);
    textUtilisateur.setCharacterSize(15);
    textVoirEvenements.setCharacterSize(20);
    textAcheterTicket.setCharacterSize(20);
    textVoirActualites.setCharacterSize(20);
    textFooter.setCharacterSize(15);
    // set the color #585858
    textBienvenue.setFillColor(sf::Color(88, 88, 88));
    textUtilisateur.setFillColor(sf::Color(88, 88, 88));
    textVoirEvenements.setFillColor(sf::Color(88, 88, 88));
    textAcheterTicket.setFillColor(sf::Color(88, 88, 88));
    textVoirActualites.setFillColor(sf::Color(88, 88, 88));
    textFooter.setFillColor(sf::Color(88, 88, 88));

    // center the textBienvenue on the screen
    textBienvenue.setPosition(
            sf::Vector2f(static_cast<float>(mainWindow.getSize().x / 2. - textBienvenue.getGlobalBounds().width / 2.),
                         static_cast<float>(mainWindow.getSize().y / 2.)));
    // textUtilisteur in the top right corner
    textUtilisateur.setPosition(sf::Vector2f(mainWindow.getSize().x - textUtilisateur.getGlobalBounds().width - 20,
                                             20));

    // textVoirEvenements in the left below textBienvenue
    textVoirEvenements.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - 4 * textVoirEvenements.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    // textAcheterTicket in the right below textBienvenue
    textAcheterTicket.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. + 1.5 * textAcheterTicket.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    // textVoirActualites in the middle below textBienvenue
    textVoirActualites.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - textVoirActualites.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 150));

    // textFooter in the bottom center
    textFooter.setPosition(sf::Vector2f(mainWindow.getSize().x / 2. - textFooter.getGlobalBounds().width / 2.,
                                        mainWindow.getSize().y - textFooter.getGlobalBounds().height - 20));
    // button
    sf::RectangleShape buttonVoirEvenements(sf::Vector2f(textVoirEvenements.getGlobalBounds().width + 20,
                                                         textVoirEvenements.getGlobalBounds().height + 20));
    buttonVoirEvenements.setFillColor(sf::Color(250, 250, 250));
    buttonVoirEvenements.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - 4 * textVoirEvenements.getGlobalBounds().width / 2. - 10,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 90));

    sf::RectangleShape buttonAcheterTicket(sf::Vector2f(textAcheterTicket.getGlobalBounds().width + 20,
                                                        textAcheterTicket.getGlobalBounds().height + 20));
    buttonAcheterTicket.setFillColor(sf::Color(250, 250, 250));
    buttonAcheterTicket.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. + 1.5 * textAcheterTicket.getGlobalBounds().width / 2. - 10,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 90));

    sf::RectangleShape buttonVoirActualites(sf::Vector2f(textVoirActualites.getGlobalBounds().width + 20,
                                                         textVoirActualites.getGlobalBounds().height + 20));
    buttonVoirActualites.setFillColor(sf::Color(250, 250, 250));
    buttonVoirActualites.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - textVoirActualites.getGlobalBounds().width / 2. - 10,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 140));

    while (mainWindow.isOpen()) {
        sf::Event event;
        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) mainWindow.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = mainWindow.mapPixelToCoords(sf::Mouse::getPosition(mainWindow));
                    if (buttonVoirEvenements.getGlobalBounds().contains(mousePos)) {
                        buttonVoirEvenements.setFillColor(sf::Color::White);
                        pageEvenements();
                    } else if (buttonAcheterTicket.getGlobalBounds().contains(mousePos)) {
                        buttonAcheterTicket.setFillColor(sf::Color::White);
                        pageBilleterie();
                    } else if (buttonVoirActualites.getGlobalBounds().contains(mousePos)) {
                        buttonVoirActualites.setFillColor(sf::Color::White);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    buttonVoirEvenements.setFillColor(sf::Color(250, 250, 250));
                    buttonAcheterTicket.setFillColor(sf::Color(250, 250, 250));
                    buttonVoirActualites.setFillColor(sf::Color(250, 250, 250));

                }
            }
        }
        mainWindow.clear(sf::Color(250, 250, 250));
        // Draw the logoJO in the middle top of the mainWindow
        logoJO.setPosition(mainWindow.getSize().x / 2., mainWindow.getSize().y / 6.);
        mainWindow.draw(logoJO);
        mainWindow.draw(textBienvenue);
        mainWindow.draw(textUtilisateur);

        mainWindow.draw(buttonVoirEvenements);
        mainWindow.draw(textVoirEvenements);

        mainWindow.draw(buttonAcheterTicket);
        mainWindow.draw(textAcheterTicket);

        mainWindow.draw(buttonVoirActualites);
        mainWindow.draw(textVoirActualites);

        mainWindow.draw(textFooter);
        mainWindow.display();
    }
    return 0;
}

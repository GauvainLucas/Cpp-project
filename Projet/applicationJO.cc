#include <SFML/Graphics.hpp>
#include <iostream>
#include "applicationJO.hh"
#include "pageEvenements.hpp"
#include "pageBilleterie.hpp"
#include "pageProfil.hpp"
#include "pageActualites.hpp"

// Déclaration des utilisateurs
UtilisateurVIP johnDoe("Doe", "John", "johndoe@example.com", "06 07 06 07 06", "jdoe", "1234", "VIP");
UtilisateurPublic janeDoe("Doe", "Jane", "janedoe@example.com", "07 06 07 06 07", "jane", "1234", "Public");
Utilisateur *utilisateurCourant = &johnDoe;

int main() {

    sf::RenderWindow mainWindow(sf::VideoMode(1000, 800), "Application JO");
    mainWindow.setPosition(sf::Vector2i(500, 100));

    sf::Texture texture;
    if (!texture.loadFromFile("../images/logoJO.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit(-1);
    }
    texture.setSmooth(true);
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
        exit(-1);
    }
    textBienvenue.setFont(font);
    textUtilisateur.setFont(font);
    textVoirEvenements.setFont(font);
    textAcheterTicket.setFont(font);
    textVoirActualites.setFont(font);
    textFooter.setFont(font);

    textBienvenue.setString("Bienvenue sur l'application des JO de Paris 2024 !");
    textUtilisateur.setString(utilisateurCourant->getPrenom() + " " + utilisateurCourant->getNom() + "\n" +
                              utilisateurCourant->getType());
    textVoirEvenements.setString("Voir les evenements");
    textAcheterTicket.setString("Acceder a la billeterie");
    textVoirActualites.setString("Dernieres actualites");
    textFooter.setString("Paris 2024 - Designed by Lucas Gauvain & Jacky Chui - All rights reserved");

    textBienvenue.setCharacterSize(24);
    textUtilisateur.setCharacterSize(15);
    textVoirEvenements.setCharacterSize(20);
    textAcheterTicket.setCharacterSize(20);
    textVoirActualites.setCharacterSize(20);
    textFooter.setCharacterSize(15);

    textBienvenue.setFillColor(sf::Color(88, 88, 88));
    textUtilisateur.setFillColor(sf::Color(88, 88, 88));
    textVoirEvenements.setFillColor(sf::Color(88, 88, 88));
    textAcheterTicket.setFillColor(sf::Color(88, 88, 88));
    textVoirActualites.setFillColor(sf::Color(88, 88, 88));
    textFooter.setFillColor(sf::Color(88, 88, 88));


    textBienvenue.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - textBienvenue.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2.));
    textUtilisateur.setPosition(
            sf::Vector2f(mainWindow.getSize().x - textUtilisateur.getGlobalBounds().width - 20, 20));
    textVoirEvenements.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - 4 * textVoirEvenements.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    textAcheterTicket.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. + 1.5 * textAcheterTicket.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    textVoirActualites.setPosition(
            sf::Vector2f(mainWindow.getSize().x / 2. - textVoirActualites.getGlobalBounds().width / 2.,
                         mainWindow.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 150));
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

    sf::RectangleShape buttonVotreCompte(sf::Vector2f(textUtilisateur.getGlobalBounds().width + 20,
                                                      textUtilisateur.getGlobalBounds().height + 20));
    buttonVotreCompte.setFillColor(sf::Color(250, 250, 250));
    buttonVotreCompte.setPosition(textUtilisateur.getPosition().x - 10, textUtilisateur.getPosition().y);
    while (mainWindow.isOpen()) {
        sf::Event event;
        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) mainWindow.close();
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePos = mainWindow.mapPixelToCoords(sf::Mouse::getPosition(mainWindow));
                if (buttonVoirEvenements.getGlobalBounds().contains(mousePos)) {
                    textVoirEvenements.setFillColor(sf::Color::Black);
                } else {
                    textVoirEvenements.setFillColor(sf::Color(88, 88, 88));
                }
                if (buttonAcheterTicket.getGlobalBounds().contains(mousePos)) {
                    textAcheterTicket.setFillColor(sf::Color::Black);
                } else {
                    textAcheterTicket.setFillColor(sf::Color(88, 88, 88));
                }
                if (buttonVoirActualites.getGlobalBounds().contains(mousePos)) {
                    textVoirActualites.setFillColor(sf::Color::Black);
                } else {
                    textVoirActualites.setFillColor(sf::Color(88, 88, 88));
                }
                if (buttonVotreCompte.getGlobalBounds().contains(mousePos)) {
                    textUtilisateur.setFillColor(sf::Color::Black);
                } else {
                    textUtilisateur.setFillColor(sf::Color(88, 88, 88));
                }
            }
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
                        pageActualites();
                    } else if (buttonVotreCompte.getGlobalBounds().contains(mousePos)) {
                        buttonVotreCompte.setFillColor(sf::Color::White);
                        pageProfil();
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    buttonVoirEvenements.setFillColor(sf::Color(250, 250, 250));
                    buttonAcheterTicket.setFillColor(sf::Color(250, 250, 250));
                    buttonVoirActualites.setFillColor(sf::Color(250, 250, 250));
                    buttonVotreCompte.setFillColor(sf::Color(250, 250, 250));

                }
            }
        }

        mainWindow.clear(sf::Color(250, 250, 250));
        logoJO.setPosition(mainWindow.getSize().x / 2., mainWindow.getSize().y / 6.);
        mainWindow.draw(logoJO);
        mainWindow.draw(textBienvenue);
        mainWindow.draw(buttonVotreCompte);
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

#include "pageProfil.hpp"
#include <SFML/Graphics.hpp>
#include "ApplicationJO.hh"
#include "utilisateur.hh"
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"
#include <iostream>

void pageProfil() {
    sf::RenderWindow pageProfil(sf::VideoMode(1000, 800), "Espace personnel");
    pageProfil.setPosition(sf::Vector2i(500, 100));
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }

    // image
    sf::Texture texture;
    if (!texture.loadFromFile("../images/user.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit(-1);
    }
    texture.setSmooth(true);
    sf::Sprite photoDeProfil;
    photoDeProfil.setTexture(texture);
    sf::FloatRect spriteSize = photoDeProfil.getGlobalBounds();
    photoDeProfil.setOrigin(static_cast<float>(spriteSize.width / 2.), static_cast<float>(spriteSize.height / 2.));
    photoDeProfil.setScale(0.5, 0.5);
    photoDeProfil.setPosition(pageProfil.getSize().x / 1.2, pageProfil.getSize().y / 6.2);

    // Text de présentation
    sf::Text textPresentation;
    textPresentation.setFont(font);
    textPresentation.setString(utilisateurCourant->getPrenom() + "\n" +
                               utilisateurCourant->getNom() + "\n" +
                               utilisateurCourant->getMail() + "\n" +
                               utilisateurCourant->getTelephone() + "\n" +
                               utilisateurCourant->getType());

    textPresentation.setCharacterSize(18);
    textPresentation.setFillColor(sf::Color(88, 88, 88));
    textPresentation.setPosition(
            sf::Vector2f(pageProfil.getSize().x / 1.8 - textPresentation.getGlobalBounds().width / 2.,
                         70));


    // ligne de séparation
    sf::RectangleShape ligneDeSeparation(sf::Vector2f(pageProfil.getSize().x, 2.f));
    ligneDeSeparation.setFillColor(sf::Color(88, 88, 88));
    ligneDeSeparation.setPosition(0, pageProfil.getSize().y / 3.);


    // text ticket acheté
    sf::Text textTicketPublicAchete;
    textTicketPublicAchete.setFont(font);
    textTicketPublicAchete.setString("Tickets achetes :\n");
    textTicketPublicAchete.setCharacterSize(22);
    textTicketPublicAchete.setFillColor(sf::Color(88, 88, 88));
    textTicketPublicAchete.setPosition(
            sf::Vector2f(pageProfil.getSize().x / 6. - textTicketPublicAchete.getGlobalBounds().width / 2.,
                         pageProfil.getSize().y / 2.5));

    // affichage des tickets achetés
    std::vector<sf::Text> ticketsTexts;
    for (int i = 0; i < utilisateurCourant->getListeTickets().size(); i++) {
        sf::Text textTicketAchete;
        textTicketAchete.setFont(font);
        textTicketAchete.setCharacterSize(18);
        textTicketAchete.setFillColor(sf::Color(88, 88, 88));
        textTicketAchete.setString(utilisateurCourant->getListeTickets()[i].getNom() + "\n" +
                                   utilisateurCourant->getListeTickets()[i].getSport() + "\n" +
                                   utilisateurCourant->getListeTickets()[i].getDate() + "\n" +
                                   utilisateurCourant->getListeTickets()[i].getLieu() + "\n" +
                                   "-------------------------");
        textTicketAchete.setPosition(
                sf::Vector2f(pageProfil.getSize().x / 6. - textTicketAchete.getGlobalBounds().width / 2.,
                             pageProfil.getSize().y / 2.5 + 50 + i * 100));
        ticketsTexts.push_back(textTicketAchete);
    }

// ...


    while (pageProfil.isOpen()) {
        sf::Event event;
        while (pageProfil.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pageProfil.close();
            }
        }
        pageProfil.clear(sf::Color(250, 250, 250));
        pageProfil.draw(photoDeProfil);
        pageProfil.draw(textPresentation);
        pageProfil.draw(ligneDeSeparation);
        pageProfil.draw(textTicketPublicAchete);
        for (auto &textTicketAchete : ticketsTexts) {
            pageProfil.draw(textTicketAchete);
        }
        pageProfil.display();
    }

}
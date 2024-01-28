#include "pageProfil.hpp"
#include <SFML/Graphics.hpp>
#include "ApplicationJO.hh"
#include "evenement.hh"
#include <iostream>

void pageProfil() {
    sf::RenderWindow pageProfil(sf::VideoMode(1000, 800), "Espace personnel");
    pageProfil.setPosition(sf::Vector2i(500, 100));
    sf::Font font;
    if (!font.loadFromFile("fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }
    // image
    sf::Texture textureAnneauJO;
    if (!textureAnneauJO.loadFromFile("images/anneauJO.png")) {
        std::cerr << "Error while loading textureAnneauJO" << std::endl;
        exit(-1);
    }
    textureAnneauJO.setSmooth(true);
    sf::Sprite imageAnneauJO;
    imageAnneauJO.setTexture(textureAnneauJO);
    sf::FloatRect spriteAnneauJO = imageAnneauJO.getGlobalBounds();
    imageAnneauJO.setOrigin(static_cast<float>(spriteAnneauJO.width / 2.),
                            static_cast<float>(spriteAnneauJO.height / 2.));
    imageAnneauJO.setScale(0.4, 0.4);
    imageAnneauJO.setPosition(pageProfil.getSize().x / 5.5, pageProfil.getSize().y / 6.4);

    // image
    sf::Texture texture;
    if (!texture.loadFromFile("images/user.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit(-1);
    }
    texture.setSmooth(true);
    sf::Sprite photoDeProfil;
    photoDeProfil.setTexture(texture);
    sf::FloatRect spriteUser = photoDeProfil.getGlobalBounds();
    photoDeProfil.setOrigin(static_cast<float>(spriteUser.width / 2.), static_cast<float>(spriteUser.height / 2.));
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
        sf::Text texteBoutonAnnuler;
        textTicketAchete.setFont(font);
        textTicketAchete.setCharacterSize(18);
        textTicketAchete.setFillColor(sf::Color(88, 88, 88));
        textTicketAchete.setString(utilisateurCourant->getListeTickets()[i].getNom() + "\n" +
                                   utilisateurCourant->getListeTickets()[i].getDate() + "\n" +
                                   utilisateurCourant->getListeTickets()[i].getLieu() + "\n" +
                                   "-------------------------");
        textTicketAchete.setPosition(
                sf::Vector2f(pageProfil.getSize().x / 6. - textTicketAchete.getGlobalBounds().width / 2.,
                             pageProfil.getSize().y / 2.5 + 50 + i * 100));

        ticketsTexts.push_back(textTicketAchete);
    }
    std::vector<sf::RectangleShape> boutonsAnnulerTickets;
    std::vector<sf::Text> textesBoutonAnnuler;
    for (int i = 0; i < utilisateurCourant->getListeTickets().size(); i++) {
        sf::RectangleShape boutonAnnuler(sf::Vector2f(100, 50));
        sf::Text texteBoutonAnnuler;
        texteBoutonAnnuler.setFont(font);
        texteBoutonAnnuler.setCharacterSize(18);
        texteBoutonAnnuler.setFillColor(sf::Color::White);
        texteBoutonAnnuler.setString("Annuler");
        boutonAnnuler.setFillColor(sf::Color::Red);
        boutonsAnnulerTickets.push_back(boutonAnnuler);
        textesBoutonAnnuler.push_back(texteBoutonAnnuler);
    }

    for (int i = 0; i < ticketsTexts.size(); i++) {
        boutonsAnnulerTickets[i].setPosition(
                ticketsTexts[i].getPosition().x + ticketsTexts[i].getGlobalBounds().width + 10,
                ticketsTexts[i].getPosition().y);
    }
    for (int i = 0; i < textesBoutonAnnuler.size(); i++) {
        textesBoutonAnnuler[i].setPosition(boutonsAnnulerTickets[i].getPosition().x + 10,
                                           boutonsAnnulerTickets[i].getPosition().y + 10);
    }

    sf::Text textTicketVIPAchete;
    std::vector<sf::Text> ticketsVIPTexts;
    std::vector<sf::RectangleShape> boutonsAnnulerTicketsVIP;
    std::vector<sf::Text> textesBoutonAnnulerVIP;
    if (utilisateurCourant->getType() == "VIP") {
        // text ticket VIP acheté
        textTicketVIPAchete.setFont(font);
        textTicketVIPAchete.setString("Tickets VIP achetes :\n");
        textTicketVIPAchete.setCharacterSize(22);
        textTicketVIPAchete.setFillColor(sf::Color(88, 88, 88));
        textTicketVIPAchete.setPosition(
                sf::Vector2f(pageProfil.getSize().x / 1.5 - textTicketVIPAchete.getGlobalBounds().width / 2.,
                             pageProfil.getSize().y / 2.5));

        // affichage des tickets VIP achetés
        for (int i = 0; i < utilisateurCourant->getListeTicketsVIP().size(); i++) {
            sf::Text ListTicketsVIPachete;
            ListTicketsVIPachete.setFont(font);
            ListTicketsVIPachete.setCharacterSize(18);
            ListTicketsVIPachete.setFillColor(sf::Color(88, 88, 88));
            ListTicketsVIPachete.setString(utilisateurCourant->getListeTicketsVIP()[i].getNom() + "\n" +
                                           utilisateurCourant->getListeTicketsVIP()[i].getDate() + "\n" +
                                           utilisateurCourant->getListeTicketsVIP()[i].getLieu() + "\n" +
                                           "-------------------------");
            ListTicketsVIPachete.setPosition(
                    sf::Vector2f(pageProfil.getSize().x / 1.5 - ListTicketsVIPachete.getGlobalBounds().width / 2.,
                                 pageProfil.getSize().y / 2.5 + 50 + i * 100));
            ticketsVIPTexts.push_back(ListTicketsVIPachete);
        }
        // boutons annuler tickets VIP
        for (int i = 0; i < utilisateurCourant->getListeTicketsVIP().size(); i++) {
            sf::RectangleShape boutonAnnulerVIP(sf::Vector2f(100, 50));
            sf::Text texteBoutonAnnulerVIP;
            texteBoutonAnnulerVIP.setFont(font);
            texteBoutonAnnulerVIP.setCharacterSize(18);
            texteBoutonAnnulerVIP.setFillColor(sf::Color::White);
            texteBoutonAnnulerVIP.setString("Annuler");
            boutonAnnulerVIP.setFillColor(sf::Color::Red);
            boutonsAnnulerTicketsVIP.push_back(boutonAnnulerVIP);
            textesBoutonAnnulerVIP.push_back(texteBoutonAnnulerVIP);
        }
        for (int i = 0; i < ticketsVIPTexts.size(); i++) {
            boutonsAnnulerTicketsVIP[i].setPosition(
                    ticketsVIPTexts[i].getPosition().x + ticketsVIPTexts[i].getGlobalBounds().width + 10,
                    ticketsVIPTexts[i].getPosition().y);
        }
        for (int i = 0; i < textesBoutonAnnulerVIP.size(); i++) {
            textesBoutonAnnulerVIP[i].setPosition(boutonsAnnulerTicketsVIP[i].getPosition().x + 10,
                                                  boutonsAnnulerTicketsVIP[i].getPosition().y + 10);
        }

    }

    while (pageProfil.isOpen()) {
        sf::Event event;
        while (pageProfil.pollEvent(event)) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(pageProfil);
                for (int i = 0; i < boutonsAnnulerTickets.size(); i++) {
                    if (boutonsAnnulerTickets[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (utilisateurCourant->annulerTicket(utilisateurCourant->getListeTickets()[i])) {
                            ticketsTexts.erase(ticketsTexts.begin() + i);
                            boutonsAnnulerTickets.erase(boutonsAnnulerTickets.begin() + i);
                        }
                    }
                }
                if (utilisateurCourant->getType() == "VIP") {
                    for (int i = 0; i < boutonsAnnulerTicketsVIP.size(); i++) {
                        if (boutonsAnnulerTicketsVIP[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "bouton annuler ticket VIP" << std::endl;
                            if (utilisateurCourant->annulerTicket(utilisateurCourant->getListeTicketsVIP()[i])) {
                                std::cout << "Ticket VIP annule" << std::endl;
                                ticketsVIPTexts.erase(ticketsVIPTexts.begin() + i);
                                boutonsAnnulerTicketsVIP.erase(boutonsAnnulerTicketsVIP.begin() + i);
                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::Closed) {
                pageProfil.close();
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (event.mouseWheelScroll.delta > 0) {
                        // le texte se déplace vers le haut
                        for (auto &textTicketAchete: ticketsTexts) {
                            textTicketAchete.move(0, -10);
                            if (textTicketAchete.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                textTicketAchete.move(0, 1000);
                            }
                        }
                        // le bouton annuler se déplace vers le haut
                        for (auto &boutonAnnuler: boutonsAnnulerTickets) {
                            boutonAnnuler.move(0, -10);
                            if (boutonAnnuler.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                boutonAnnuler.move(0, 1000);
                            }
                        }
                        // le texte du bouton annuler se déplace vers le haut
                        for (auto &texteBoutonAnnuler: textesBoutonAnnuler) {
                            texteBoutonAnnuler.move(0, -10);
                            if (texteBoutonAnnuler.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                texteBoutonAnnuler.move(0, 1000);
                            }
                        }
                        if (utilisateurCourant->getType() == "VIP") {
                            // textTicketVIPAchete.move(0, -10);
                            for (auto &ListTicketsVIPachete: ticketsVIPTexts) {
                                ListTicketsVIPachete.move(0, -10);
                                if (ListTicketsVIPachete.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                    // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                    ListTicketsVIPachete.move(0, 1000);
                                }
                            }
                            for (auto &boutonAnnulerVIP: boutonsAnnulerTicketsVIP) {
                                boutonAnnulerVIP.move(0, -10);
                                if (boutonAnnulerVIP.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                    // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                    boutonAnnulerVIP.move(0, 1000);
                                }
                            }
                            for (auto &texteBoutonAnnulerVIP: textesBoutonAnnulerVIP) {
                                texteBoutonAnnulerVIP.move(0, -10);
                                if (texteBoutonAnnulerVIP.getPosition().y < ligneDeSeparation.getPosition().y + 100) {
                                    // monter mais ne pas afficher les tickets au dessus de la ligne de séparation
                                    texteBoutonAnnulerVIP.move(0, 1000);
                                }
                            }
                        }
                    } else if (event.mouseWheelScroll.delta < 0) {
                        for (auto &textTicketAchete: ticketsTexts) {
                            textTicketAchete.move(0, 10);
                            if (textTicketAchete.getPosition().y > pageProfil.getSize().y - 100) {
                                // descendre mais ne pas afficher les tickets en dessous du footer
                                textTicketAchete.move(0, -1000);
                            }
                        }
                        for (auto &boutonAnnuler: boutonsAnnulerTickets) {
                            boutonAnnuler.move(0, 10);
                            if (boutonAnnuler.getPosition().y > pageProfil.getSize().y - 100) {
                                // descendre mais ne pas afficher les tickets en dessous du footer
                                boutonAnnuler.move(0, -1000);
                            }
                        }
                        for (auto &texteBoutonAnnuler: textesBoutonAnnuler) {
                            texteBoutonAnnuler.move(0, 10);
                            if (texteBoutonAnnuler.getPosition().y > pageProfil.getSize().y - 100) {
                                // descendre mais ne pas afficher les tickets en dessous du footer
                                texteBoutonAnnuler.move(0, -1000);
                            }
                        }
                        if (utilisateurCourant->getType() == "VIP") {
                            for (auto &ListTicketsVIPachete: ticketsVIPTexts) {
                                ListTicketsVIPachete.move(0, 10);
                                if (ListTicketsVIPachete.getPosition().y > pageProfil.getSize().y - 100) {
                                    // descendre mais ne pas afficher les tickets en dessous du footer
                                    ListTicketsVIPachete.move(0, -1000);
                                }
                            }
                            for (auto &boutonAnnulerVIP: boutonsAnnulerTicketsVIP) {
                                boutonAnnulerVIP.move(0, 10);
                                if (boutonAnnulerVIP.getPosition().y > pageProfil.getSize().y - 100) {
                                    // descendre mais ne pas afficher les tickets en dessous du footer
                                    boutonAnnulerVIP.move(0, -1000);
                                }
                            }
                            for (auto &texteBoutonAnnulerVIP: textesBoutonAnnulerVIP) {
                                texteBoutonAnnulerVIP.move(0, 10);
                                if (texteBoutonAnnulerVIP.getPosition().y > pageProfil.getSize().y - 100) {
                                    // descendre mais ne pas afficher les tickets en dessous du footer
                                    texteBoutonAnnulerVIP.move(0, -1000);
                                }
                            }
                        }
                    }
                }
            }
        }
        pageProfil.clear(sf::Color(250, 250, 250));
        pageProfil.draw(imageAnneauJO);
        pageProfil.draw(photoDeProfil);
        pageProfil.draw(textPresentation);
        pageProfil.draw(ligneDeSeparation);
        pageProfil.draw(textTicketPublicAchete);
        for (auto &textTicketAchete: ticketsTexts) {
            pageProfil.draw(textTicketAchete);
        }
        // Draw the cancel buttons
        for (auto &boutonAnnuler: boutonsAnnulerTickets) {
            pageProfil.draw(boutonAnnuler);
        }
        for (auto &texteBoutonAnnuler: textesBoutonAnnuler) {
            pageProfil.draw(texteBoutonAnnuler);
        }

        if (utilisateurCourant->getType() == "VIP") {
            pageProfil.draw(textTicketVIPAchete);
            for (auto &textTicketVIPAchete: ticketsVIPTexts) {
                pageProfil.draw(textTicketVIPAchete);
            }
            for (auto &boutonAnnulerVIP: boutonsAnnulerTicketsVIP) {
                pageProfil.draw(boutonAnnulerVIP);
            }
            for (auto &texteBoutonAnnulerVIP: textesBoutonAnnulerVIP) {
                pageProfil.draw(texteBoutonAnnulerVIP);
            }
        }
        pageProfil.display();
    }

}
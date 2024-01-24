#include <SFML/Graphics.hpp>
#include <iostream>
#include "pageEvenements.hpp"
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"
#include <vector>

void pageEvenements(){

    sf::RenderWindow pageEvenements(sf::VideoMode(1000, 800), "Les evenements");
    pageEvenements.setPosition(sf::Vector2i(500, 100));

    // Evenements
    std::vector<Evenement*> listEvenementsEnCours;
    EvenementSportif* premierDirect = new EvenementSportif("Finale 400m Homme",
                                                           "Aujourd'hui - 14h",
                                                           "Stade Charlety",
                                                           "Places disponibles : 43",
                                                           "", "Athletisme");
    EvenementSportif* deuxiemeDirect = new EvenementSportif("Finale 100m Homme",
                                                            "Aujourd'hui - 14h30",
                                                            "Stade Montreuil",
                                                            "Aller Daviiiiiid !",
                                                            "", "Athletisme");
    EvenementCeremonie* premiereCeremonie = new EvenementCeremonie("Remise medailles 400m Femme",
                                                                   "Aujourd'hui - 14h",
                                                                   "Tour Eiffel",
                                                                   "Annonce du podium",
                                                                   "", "Ceremonie");
    EvenementCeremonie* deuxiemeCeremonie = new EvenementCeremonie("Remise medailles 100m Femme",
                                                                   "Aujourd'hui - 14h30",
                                                                   "Tour Eiffel",
                                                                   "Annonce du podium",
                                                                   "", "Ceremonie");


    // ajouter les evenements a la liste
    listEvenementsEnCours.push_back(premierDirect);
    listEvenementsEnCours.push_back(deuxiemeDirect);
    listEvenementsEnCours.push_back(premiereCeremonie);
    listEvenementsEnCours.push_back(deuxiemeCeremonie);
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }

    // Text
    sf::Text textTitre;
    textTitre.setFont(font); // font is a sf::Font
    textTitre.setString("PARIS 2024 - LES EVENEMENTS");
    textTitre.setCharacterSize(25);
    textTitre.setFillColor(sf::Color(88, 88, 88));
    textTitre.setPosition(
            pageEvenements.getSize().x / 2 - textTitre.getGlobalBounds().width / 2, 0);

    sf::Text textEvenementsEnCours;
    textEvenementsEnCours.setFont(font); // font is a sf::Font
    textEvenementsEnCours.setString("Evenements en cours");
    textEvenementsEnCours.setCharacterSize(20);
    textEvenementsEnCours.setFillColor(sf::Color(88, 88, 88));
    textEvenementsEnCours.setPosition(
            pageEvenements.getSize().x / 6 - textEvenementsEnCours.getGlobalBounds().width / 2, 100);

    sf::Text textEvenementsFuturs;
    textEvenementsFuturs.setFont(font); // font is a sf::Font
    textEvenementsFuturs.setString("Evenements a venir");
    textEvenementsFuturs.setCharacterSize(20);
    textEvenementsFuturs.setFillColor(sf::Color(88, 88, 88));
    textEvenementsFuturs.setPosition(
            pageEvenements.getSize().x / 2 + 2*textEvenementsFuturs.getGlobalBounds().width / 2, 100);

    sf::Text textDirect;
    textDirect.setFont(font); // font is a sf::Font
    textDirect.setString(listEvenementsEnCours[0]->afficherEvenements(listEvenementsEnCours));
    textDirect.setCharacterSize(18);
    textDirect.setFillColor(sf::Color(88, 88, 88));
    textDirect.setPosition(
            pageEvenements.getSize().x / 6 - textDirect.getGlobalBounds().width / 2, 150);

    while (pageEvenements.isOpen()) {
        sf::Event event;
        while (pageEvenements.pollEvent(event)) {
            if (event.type == sf::Event::Closed) pageEvenements.close();
        }
        pageEvenements.clear(sf::Color(250, 250, 250));
        //affichage des elements
        pageEvenements.draw(textTitre);
        pageEvenements.draw(textEvenementsEnCours);
        pageEvenements.draw(textEvenementsFuturs);
        pageEvenements.draw(textDirect);
        pageEvenements.display();
    }
}
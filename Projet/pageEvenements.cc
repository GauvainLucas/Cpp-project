#include <SFML/Graphics.hpp>
#include <iostream>
#include "pageEvenements.hpp"
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"
#include <vector>

void pageEvenements() {

    sf::RenderWindow pageEvenements(sf::VideoMode(1000, 800), "Les evenements");
    pageEvenements.setPosition(sf::Vector2i(500, 100));

    // image
    sf::Texture texture;
    if (!texture.loadFromFile("images/imagePageEvenement.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        exit(-1);
    }
    sf::Sprite imagePageEvenement;
    imagePageEvenement.setTexture(texture);
    sf::FloatRect spriteSize = imagePageEvenement.getGlobalBounds();
    texture.setSmooth(true);
    sf::Color couleur = imagePageEvenement.getColor();
    couleur.a = 128; // 50% transparent
    imagePageEvenement.setColor(couleur);

    // centrer l'image
    imagePageEvenement.setOrigin(static_cast<float>(spriteSize.width / 2.), static_cast<float>(spriteSize.height / 2.));
    imagePageEvenement.setPosition(pageEvenements.getSize().x / 2, pageEvenements.getSize().y / 2);
    imagePageEvenement.setScale(0.2, 0.2);



    // Evenements
    std::vector<Evenement *> listEvenementsEnCours;
    std::vector<Evenement *> listEvenementsFuturs;
    EvenementSportif *premierDirect = new EvenementSportif("Finale Saut en longueur Homme",
                                                           "Aujourd'hui - 14h",
                                                           "Stade Charlety",
                                                           "Places disponibles : 43",
                                                           "Public", "Athletisme");
    EvenementSportif *deuxiemeDirect = new EvenementSportif("Finale 100m Homme",
                                                            "Aujourd'hui - 14h30",
                                                            "Stade Montreuil",
                                                            "Aller Daviiiiiid !",
                                                            "Public", "Athletisme");
    EvenementCeremonie *troisiemeDirect = new EvenementCeremonie("Remise medailles 400m Femme",
                                                                 "Aujourd'hui - 14h",
                                                                 "Tour Eiffel",
                                                                 "Annonce du podium",
                                                                 "VIP", "Ceremonie");
    EvenementCeremonie *quatriemeDirect = new EvenementCeremonie("Remise medailles 100m Femme",
                                                                 "Aujourd'hui - 14h30",
                                                                 "Tour Eiffel",
                                                                 "Annonce du podium",
                                                                 "VIP", "Ceremonie");

    EvenementSportif *premierFutur = new EvenementSportif("Quart de finale - France vs USA",
                                                          "Demain - 9h",
                                                          "Saint-Denis",
                                                          "Places disponibles : 1",
                                                          "Public", "Basketball");

    EvenementSportif *deuxiemeFutur = new EvenementSportif("Demi finale - Allemagne vs Espagne",
                                                           "Demain - 10h30",
                                                           "Parc des Princes",
                                                           "Places disponibles : 97",
                                                           "Public", "Football");

    EvenementCeremonie *troisiemeFutur = new EvenementCeremonie("Remise medailles 400m Homme",
                                                                "Demain - 14h",
                                                                "Tour Eiffel",
                                                                "Annonce du podium",
                                                                "VIP", "Ceremonie");

    EvenementCeremonie *quatriemeFutur = new EvenementCeremonie("Remise medailles 100m Homme",
                                                                "Demain - 15h",
                                                                "Arc de Triomphe",
                                                                "Annonce du podium",
                                                                "VIP", "Ceremonie");


    // ajouter les evenements a la liste
    listEvenementsEnCours.push_back(premierDirect);
    listEvenementsEnCours.push_back(deuxiemeDirect);
    listEvenementsEnCours.push_back(troisiemeDirect);
    listEvenementsEnCours.push_back(quatriemeDirect);
    listEvenementsFuturs.push_back(premierFutur);
    listEvenementsFuturs.push_back(deuxiemeFutur);
    listEvenementsFuturs.push_back(troisiemeFutur);
    listEvenementsFuturs.push_back(quatriemeFutur);
    sf::Font font;
    if (!font.loadFromFile("fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }

    // Texte
    sf::Text textTitre;
    textTitre.setFont(font);
    textTitre.setString("PARIS 2024 - LES EVENEMENTS");
    textTitre.setCharacterSize(25);
    textTitre.setFillColor(sf::Color(88, 88, 88));
    textTitre.setPosition(
            pageEvenements.getSize().x / 2 - textTitre.getGlobalBounds().width / 2, 0);

    sf::Text textEvenementsEnCours;
    textEvenementsEnCours.setFont(font);
    textEvenementsEnCours.setString("Evenements en cours");
    textEvenementsEnCours.setCharacterSize(20);
    textEvenementsEnCours.setFillColor(sf::Color(88, 88, 88));
    textEvenementsEnCours.setPosition(
            pageEvenements.getSize().x / 6 - textEvenementsEnCours.getGlobalBounds().width / 2, 100);

    sf::Text textEvenementsFuturs;
    textEvenementsFuturs.setFont(font);
    textEvenementsFuturs.setString("Evenements a venir");
    textEvenementsFuturs.setCharacterSize(20);
    textEvenementsFuturs.setFillColor(sf::Color(88, 88, 88));
    textEvenementsFuturs.setPosition(
            pageEvenements.getSize().x / 2 + 2 * textEvenementsFuturs.getGlobalBounds().width / 2, 100);

    sf::Text textDirect;
    textDirect.setFont(font);
    textDirect.setString(listEvenementsEnCours[0]->afficherEvenements(listEvenementsEnCours));
    textDirect.setCharacterSize(18);
    textDirect.setFillColor(sf::Color(88, 88, 88));
    textDirect.setPosition(
            pageEvenements.getSize().x / 6 - textDirect.getGlobalBounds().width / 2, 150);

    sf::Text textFutur;
    textFutur.setFont(font);
    textFutur.setString(listEvenementsFuturs[0]->afficherEvenements(listEvenementsFuturs));
    textFutur.setCharacterSize(18);
    textFutur.setFillColor(sf::Color(88, 88, 88));
    textFutur.setPosition(
            pageEvenements.getSize().x / 2 + textFutur.getGlobalBounds().width / 2, 150);

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
        pageEvenements.draw(textFutur);
        pageEvenements.draw(imagePageEvenement);
        pageEvenements.display();
    }
}
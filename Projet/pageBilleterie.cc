#include "pageBilleterie.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"

std::string reduiretexte(const std::string &text, std::size_t tailleMax) {
    if (text.length() > tailleMax) {
        return text.substr(0, tailleMax - 3) + "...";
    }
    return text;
}

void pageBilleterie() {
    sf::RenderWindow pageBilletterie(sf::VideoMode(1000, 800), "La billeterie officielle des JO de Paris 2024");
    pageBilletterie.setPosition(sf::Vector2i(500, 100));

    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf")) {
        std::cerr << "Error while loading font" << std::endl;
        exit(-1);
    }

    sf::RenderWindow tooltip(sf::VideoMode(200, 50), "Tooltip");
    tooltip.setVisible(false);
    sf::Text tooltipText("", font, 16);
    tooltipText.setFillColor(sf::Color(88, 88, 88));
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
    imagePageBilleterie.setOrigin(static_cast<float>(spriteSize.width / 2.),
                                  static_cast<float>(spriteSize.height / 2.));
    imagePageBilleterie.setPosition(pageBilletterie.getSize().x / 1.8, 100);
    imagePageBilleterie.setScale(0.8, 0.8);

    std::vector<Evenement *> listEvenementsAReserver;
    EvenementSportif *premier = new EvenementSportif("Finale 400m Homme",
                                                     "Aujourd'hui - 14h",
                                                     "Stade Charlety",
                                                     "Places disponibles : 43",
                                                     "Public", "Athletisme");
    EvenementSportif *deuxieme = new EvenementSportif("Finale 100m Homme",
                                                      "Aujourd'hui - 14h30",
                                                      "Stade Montreuil",
                                                      "Aller Daviiiiiid !",
                                                      "Public", "Athletisme");
    EvenementCeremonie *troisieme = new EvenementCeremonie("Remise prix 400m Femme",
                                                           "Aujourd'hui - 14h",
                                                           "Tour Eiffel",
                                                           "Annonce du podium",
                                                           "VIP", "Ceremonie");
    EvenementCeremonie *quatrieme = new EvenementCeremonie("Remise prix 100m Femme",
                                                           "Aujourd'hui - 14h30",
                                                           "Tour Eiffel",
                                                           "Annonce du podium",
                                                           "VIP", "Ceremonie");

    listEvenementsAReserver.push_back(premier);
    listEvenementsAReserver.push_back(deuxieme);
    listEvenementsAReserver.push_back(troisieme);
    listEvenementsAReserver.push_back(quatrieme);

    // Les donnees a afficher dans le tableau
    std::vector<ChartData> data;
    for (auto evenement: listEvenementsAReserver) {
        ChartData dataElement;
        dataElement.evenement = evenement->getNom();
        dataElement.date = evenement->getDate();
        dataElement.lieux = evenement->getLieu();
        dataElement.type = evenement->getType();
        dataElement.acces = evenement->getSport();
        dataElement.reserver = "Reserver";
        data.push_back(dataElement);
    }

    // Les differentes colonnes du tableau
    std::vector<std::string> columnHeaders = {"Evenement", "Date", "Lieux", "Type", "Acces", "Reserver"};

    // Mise en place des headers dans le tableau
    std::vector<sf::Text> headerTexts;
    for (const auto &header: columnHeaders) {
        sf::Text text;
        text.setFont(font);
        text.setString(header);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color(88, 88, 88));
        headerTexts.push_back(text);
    }

    // Mise en place des evenements dans le tableau
    std::vector<std::vector<sf::Text>> dataTexts(data.size(), std::vector<sf::Text>(columnHeaders.size()));
    std::vector<std::vector<std::string>> fullTexts(data.size(), std::vector<std::string>(columnHeaders.size()));

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < columnHeaders.size(); ++j) {
            sf::Text text;
            text.setFont(font);
            std::string originalText;
            switch (j) {
                case 0:
                    originalText = data[i].evenement;
                    break;
                case 1:
                    originalText = data[i].date;
                    break;
                case 2:
                    originalText = data[i].lieux;
                    break;
                case 3:
                    originalText = data[i].type;
                    break;
                case 4:
                    originalText = data[i].acces;
                    break;
                case 5:
                    originalText = "Reserver";
                    break;
            }

            fullTexts[i][j] = originalText;  // Enregistrer le texte complet
            text.setString(reduiretexte(originalText, 25)); // Tronquer le texte si trop long

            text.setCharacterSize(12);
            text.setFillColor(sf::Color(88, 88, 88));
            dataTexts[i][j] = text;
        }
    }

    // Centrer la table
    float tableWidth = static_cast<float>(columnHeaders.size()) * 150.0f;
    float tableHeight = static_cast<float>(data.size() + 1) * 30.0f;
    float tableX = (pageBilletterie.getSize().x - tableWidth) / 3.0f;
    float tableY = (pageBilletterie.getSize().y - tableHeight) / 2.0f;

    while (pageBilletterie.isOpen()) {
        sf::Event event;
        while (pageBilletterie.pollEvent(event)) {
            if (event.type == sf::Event::Closed) pageBilletterie.close();
        }
        pageBilletterie.clear(sf::Color(250, 250, 250));
        // Affichage des elements
        pageBilletterie.draw(imagePageBilleterie);
        // Affichage du tableau
        float columnWidth = 170.0f; // Taille des colonnes
        for (size_t i = 0; i < headerTexts.size(); ++i) {
            headerTexts[i].setPosition(tableX + columnWidth * i, tableY);
            pageBilletterie.draw(headerTexts[i]);
        }
        for (size_t i = 0; i < dataTexts.size(); ++i) {
            for (size_t j = 0; j < dataTexts[i].size(); ++j) {
                dataTexts[i][j].setPosition(tableX + columnWidth * j, tableY + (i + 1) * 30);
                pageBilletterie.draw(dataTexts[i][j]);
            }
        }
        pageBilletterie.display();
    }
}

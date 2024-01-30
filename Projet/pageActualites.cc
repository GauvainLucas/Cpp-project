#include "pageActualites.hpp"
#include <SFML/Graphics.hpp>
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"
#include <iostream>
#include <sstream>

std::string addLineBreaks(std::string str, unsigned int maxLineLength, sf::Font &font, unsigned int characterSize) {
    unsigned int width = 0;
    std::string result;
    std::string word;
    std::istringstream iss(str);

    while (iss >> word) {
        sf::Text tempText(word, font, characterSize);
        if (width + tempText.getLocalBounds().width > maxLineLength) {
            result += "\n" + word + " ";
            width = tempText.getLocalBounds().width;
        } else {
            result += word + " ";
            width += tempText.getLocalBounds().width;
        }
    }

    return result;
}

void pageActualites() {
    sf::RenderWindow pageActualites(sf::VideoMode(1000, 800), "Les actualites");
    pageActualites.setPosition(sf::Vector2i(500, 100));
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
    sf::FloatRect spriteSize = imageAnneauJO.getGlobalBounds();
    imageAnneauJO.setOrigin(static_cast<float>(spriteSize.width / 2.), static_cast<float>(spriteSize.height / 2.));
    imageAnneauJO.setScale(0.4, 0.4);
    imageAnneauJO.setPosition(pageActualites.getSize().x / 5.5, pageActualites.getSize().y / 6.4);

    // Text de présentation
    sf::Text textTitrePage;
    textTitrePage.setFont(font);
    textTitrePage.setString("LES DERNIERES ACTUALITES EN DIRECT");

    textTitrePage.setCharacterSize(25);
    textTitrePage.setFillColor(sf::Color(88, 88, 88));
    textTitrePage.setPosition(
            sf::Vector2f(pageActualites.getSize().x / 1.5 - textTitrePage.getGlobalBounds().width / 2.,
                         100));


    std::vector<Evenement *> listActualites;
    // Créations des actualités (Evenement)
    EvenementCeremonie *davidChampion = new EvenementCeremonie("DAVID LAMOOT CHAMPION OLYMPIQUE DU 100 METRE !",
                                                               "HIER A 16H",
                                                               "STADE OLYMPIQUE DE PARIS",

                                                               "Au sommet de sa jeunesse, David Lamoot a ebloui les Jeux Olympiques de Paris en remportant la medaille d'or au 60m, mais ce n'est pas tout :"
                                                               "il a egalement etabli un nouveau record mondial remarquable. A seulement 21 ans, Lamoot a surpasse la legende du sprint, Usain Bolt, en franchissant la ligne d'arrivee en un temps stupefiant de 9s55."
                                                               "Cette performance extraordinaire a propulse Lamoot au-dela des frontieres de l'excellence athletique, ecrivant ainsi un nouveau chapitre dans l'histoire du sprint mondial."
                                                               "Sa victoire, combinee a la conquete d'un record aussi prestigieux, a solidifie sa place en tant que jeune prodige du monde de l'athletisme, laissant presager un avenir encore plus brillant pour cet athlete exceptionnel.",
                                                               "VIP", "Ceremonie");

    EvenementCeremonie *rivaliteDavidVSMomo = new EvenementCeremonie("UNE RIVALITE LAMOOT VS GHAIBOUCHE AU MAXIMUM !",
                                                                     "HIER A 16H",
                                                                     "STADE OLYMPIQUE DE PARIS",
                                                                     "La rivalite olympique atteint son apogee avec la confrontation entre David Lamoot, le champion inconteste du 100m, et Mohammed Ghaibouche, le maitre du saut a la perche. "
                                                                     "Dans un defi inedit et audacieux, Mohammed propose un bras de fer chinois pour determiner qui est le veritable champion toutes disciplines confondues."
                                                                     "Cette rencontre promet d'etre epique, melant la vitesse foudroyante de Lamoot a l'agilite exceptionnelle de Ghaibouche. Ces deux athletes d'exception, chacun dominant dans sa discipline, sont prets a repousser les limites et a transcender les frontieres du sport."
                                                                     "La tension monte alors que le monde attend avec impatience de decouvrir qui sortira victorieux de cette confrontation extraordinaire, qui restera sans aucun doute gravee dans l'histoire du sport olympique.",
                                                                     "VIP", "Ceremonie");

    listActualites.push_back(davidChampion);
    listActualites.push_back(rivaliteDavidVSMomo);

    // images des actualités
    sf::Texture textureActualite1;
    if (!textureActualite1.loadFromFile("images/david.jpg")) {
        std::cerr << "Error while loading textureActualite1" << std::endl;
        exit(-1);
    }
    textureActualite1.setSmooth(true);
    sf::Sprite imageActualite1;
    imageActualite1.setTexture(textureActualite1);
    sf::FloatRect spriteSize1 = imageActualite1.getGlobalBounds();
    imageActualite1.setOrigin(static_cast<float>(spriteSize1.width / 2.), static_cast<float>(spriteSize1.height / 2.));
    imageActualite1.setScale(0.23, 0.23);
    imageActualite1.setPosition(pageActualites.getSize().x / 5.8, pageActualites.getSize().y / 2.1);

    sf::Texture textureActualite2;
    if (!textureActualite2.loadFromFile("images/davidVSmohamed.jpg")) {
        std::cerr << "Error while loading textureActualite2" << std::endl;
        exit(-1);
    }
    textureActualite2.setSmooth(true);
    sf::Sprite imageActualite2;
    imageActualite2.setTexture(textureActualite2);
    sf::FloatRect spriteSize2 = imageActualite2.getGlobalBounds();
    imageActualite2.setOrigin(static_cast<float>(spriteSize2.width / 2.), static_cast<float>(spriteSize2.height / 2.));
    imageActualite2.setScale(0.23, 0.23);
    imageActualite2.setPosition(pageActualites.getSize().x / 5.8, pageActualites.getSize().y / 1.2);
    
    // afficher la liste des actualités
    std::vector<sf::Text> titreActualitesVec(listActualites.size(), sf::Text());
    std::vector<sf::Text> descriptionActualitesVec(listActualites.size(), sf::Text());

    for (int i = 0; i < listActualites.size(); i++) {
        titreActualitesVec[i].setFont(font);
        titreActualitesVec[i].setString(listActualites[i]->getNom());
        titreActualitesVec[i].setCharacterSize(28);
        titreActualitesVec[i].setFillColor(sf::Color(88, 88, 88));
        titreActualitesVec[i].setPosition(
                sf::Vector2f(40, 240 + i * 280));

        std::string description = listActualites[i]->getDescription();
        std::string formattedDescription = addLineBreaks(description, pageActualites.getSize().x / 1.7, font, 15);


        descriptionActualitesVec[i].setFont(font);
        descriptionActualitesVec[i].setString(formattedDescription);
        descriptionActualitesVec[i].setCharacterSize(15);
        descriptionActualitesVec[i].setFillColor(sf::Color(88, 88, 88));
        descriptionActualitesVec[i].setPosition(
                sf::Vector2f(pageActualites.getSize().x / 3., 280 + i * 280)); // Set x-position to a constant value
    }

    while (pageActualites.isOpen()) {
        sf::Event event;
        while (pageActualites.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                pageActualites.close();
            }
        }
        pageActualites.clear(sf::Color(250, 250, 250));
        pageActualites.draw(imageAnneauJO);
        pageActualites.draw(textTitrePage);
        for (int i = 0; i < listActualites.size(); i++) {
            pageActualites.draw(titreActualitesVec[i]);
            pageActualites.draw(descriptionActualitesVec[i]);
        }
        pageActualites.draw(imageActualite1);
        pageActualites.draw(imageActualite2);
        pageActualites.display();
    }
}

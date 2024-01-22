#include <SFML/Graphics.hpp>
#include <iostream>



int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Application JO");

    // Create texture from PNG file
    sf::Texture texture;
    if (!texture.loadFromFile("../images/logoJO.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
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
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf"))
    {
        std::cerr << "Error while loading font" << std::endl;
        return -1;
    }
    // select the font
    textBienvenue.setFont(font); // font is a sf::Font
    textUtilisateur.setFont(font); // font is a sf::Font
    textVoirEvenements.setFont(font); // font is a sf::Font
    textAcheterTicket.setFont(font); // font is a sf::Font
    textVoirActualites.setFont(font); // font is a sf::Font
    // set the string to display
    textBienvenue.setString("Bienvenue sur l'application des JO de Paris 2024 !");
    textUtilisateur.setString("Nom\nPrenom\n");
    textVoirEvenements.setString("Voir les evenements");
    textAcheterTicket.setString("Acceder a la billeterie");
    textVoirActualites.setString("Dernieres actualites");
    // set the character size
    textBienvenue.setCharacterSize(24);
    textUtilisateur.setCharacterSize(15);
    textVoirEvenements.setCharacterSize(20);
    textAcheterTicket.setCharacterSize(20);
    textVoirActualites.setCharacterSize(20);
    // set the color #585858
    textBienvenue.setFillColor(sf::Color(88, 88, 88));
    textUtilisateur.setFillColor(sf::Color(88, 88, 88));
    textVoirEvenements.setFillColor(sf::Color(88, 88, 88));
    textAcheterTicket.setFillColor(sf::Color(88, 88, 88));
    textVoirActualites.setFillColor(sf::Color(88, 88, 88));

    // center the textBienvenue on the screen
    textBienvenue.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x / 2. - textBienvenue.getGlobalBounds().width / 2.),
                                           static_cast<float>(window.getSize().y / 2.)));
    // textUtilisteur in the top right corner
    textUtilisateur.setPosition(sf::Vector2f(window.getSize().x - textUtilisateur.getGlobalBounds().width - 20,
                                             20));

    // textVoirEvenements in the left below textBienvenue
    textVoirEvenements.setPosition(sf::Vector2f(window.getSize().x / 2. - 4*textVoirEvenements.getGlobalBounds().width / 2.,
                                                window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    // textAcheterTicket in the right below textBienvenue
    textAcheterTicket.setPosition(sf::Vector2f(window.getSize().x / 2. + 1.5*textAcheterTicket.getGlobalBounds().width / 2.,
                                               window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 100));
    // textVoirActualites in the middle below textBienvenue
    textVoirActualites.setPosition(sf::Vector2f(window.getSize().x / 2. - textVoirActualites.getGlobalBounds().width / 2.,
                                                window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 150));
    // button
    sf::RectangleShape buttonVoirEvenements(sf::Vector2f(textVoirEvenements.getGlobalBounds().width + 20, textVoirEvenements.getGlobalBounds().height + 20));
    buttonVoirEvenements.setFillColor(sf::Color(250, 250, 250));
    buttonVoirEvenements.setPosition(sf::Vector2f(window.getSize().x / 2. - 4*textVoirEvenements.getGlobalBounds().width / 2. - 10,
                                                   window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 90));

    sf::RectangleShape buttonAcheterTicket(sf::Vector2f(textAcheterTicket.getGlobalBounds().width + 20, textAcheterTicket.getGlobalBounds().height + 20));
    buttonAcheterTicket.setFillColor(sf::Color(250, 250, 250));
    buttonAcheterTicket.setPosition(sf::Vector2f(window.getSize().x / 2. + 1.5*textAcheterTicket.getGlobalBounds().width / 2. - 10,
                                                  window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 90));

    sf::RectangleShape buttonVoirActualites(sf::Vector2f(textVoirActualites.getGlobalBounds().width + 20, textVoirActualites.getGlobalBounds().height + 20));
    buttonVoirActualites.setFillColor(sf::Color(250, 250, 250));
    buttonVoirActualites.setPosition(sf::Vector2f(window.getSize().x / 2. - textVoirActualites.getGlobalBounds().width / 2. - 10,
                                                   window.getSize().y / 2. + textBienvenue.getGlobalBounds().height + 140));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (buttonVoirEvenements.getGlobalBounds().contains(mousePos)) {
                        // Le bouton evenement a été cliqué
                        buttonVoirEvenements.setFillColor(sf::Color::White);
                        // Ajoutez ici le code à exécuter lorsque le bouton est cliqué
                    } else if (buttonAcheterTicket.getGlobalBounds().contains(mousePos)) {
                        // Le bouton tickets a été cliqué
                        buttonAcheterTicket.setFillColor(sf::Color::White);
                        // Ajoutez ici le code à exécuter lorsque le bouton est cliqué
                    } else if (buttonVoirActualites.getGlobalBounds().contains(mousePos)) {
                        // Le bouton actualites a été cliqué
                        buttonVoirActualites.setFillColor(sf::Color::White);
                        // Ajoutez ici le code à exécuter lorsque le bouton est cliqué
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
        window.clear(sf::Color(250, 250, 250));
        // Draw the logoJO in the middle top of the window
        logoJO.setPosition(window.getSize().x / 2., window.getSize().y / 6.);
        window.draw(logoJO);
        window.draw(textBienvenue);
        window.draw(textUtilisateur);

        window.draw(buttonVoirEvenements);
        window.draw(textVoirEvenements);

        window.draw(buttonAcheterTicket);
        window.draw(textAcheterTicket);

        window.draw(buttonVoirActualites);
        window.draw(textVoirActualites);

        window.display();
    }
    return 0;
}

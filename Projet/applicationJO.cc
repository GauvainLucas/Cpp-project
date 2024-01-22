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
    logoJO.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
    logoJO.setScale(0.25, 0.25);

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("../fonts/SF-Compact-Display-Black.ttf"))
    {
        std::cerr << "Error while loading font" << std::endl;
        return -1;
    }
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("Bienvenue sur l'application des JO de Paris 2024 !");
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the color #585858
    text.setFillColor(sf::Color(88, 88, 88));
    // center the text on the screen
    text.setPosition(sf::Vector2f(window.getSize().x / 2. - text.getGlobalBounds().width / 2., window.getSize().y / 2.));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(250, 250, 250));
        // Draw the logoJO in the middle top of the window
        logoJO.setPosition(window.getSize().x / 2., window.getSize().y / 6.);
        window.draw(logoJO);
        window.draw(text);
        window.display();
    }
    return 0;
}

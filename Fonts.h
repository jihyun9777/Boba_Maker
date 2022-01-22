#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Fonts {
public:
    static sf::Font font;
    static sf::Font& getFonts ();
};
#endif //SFML_PROJECT_FONTS_H

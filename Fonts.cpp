#include "Fonts.h"

sf::Font Fonts::font;

sf::Font& Fonts::getFonts()
{
    if (!font.loadFromFile("OpenSans-Bold.ttf"))
        std::cout << "Font load failed" << std::endl;
    return font;
}

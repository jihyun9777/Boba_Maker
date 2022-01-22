#ifndef SFML_PROJECT_COLORTEXT_H
#define SFML_PROJECT_COLORTEXT_H
#include "GUI.h"
#include "DList.h"

class ColorText {
public:
    void isColorWord (DList<sf::Text>::iterator& start, DList<sf::Text>::iterator& last);
    void isNotColorWord (DList<sf::Text>::iterator& start, DList<sf::Text>::iterator& last);
    void isColorOper (DList<sf::Text>::iterator& last);
    void isColorNum (DList<sf::Text>::iterator& last);
};

#endif //SFML_PROJECT_COLORTEXT_H

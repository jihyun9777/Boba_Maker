#include "ColorText.h"

void ColorText::isColorWord (DList<sf::Text>::iterator& start, DList<sf::Text>::iterator& last)
{
    DList<sf::Text>::iterator temp;
    for(temp = start; temp != last; ++temp)
        (*temp).setFillColor(sf::Color::Blue);
}

void ColorText::isNotColorWord (DList<sf::Text>::iterator& start, DList<sf::Text>::iterator& last)
{
    DList<sf::Text>::iterator temp;
    for(temp = start; temp != last; ++temp)
        (*temp).setFillColor(sf::Color::White);
    (*temp).setFillColor(sf::Color::White);
}

void ColorText::isColorOper (DList<sf::Text>::iterator& last)
{
    (*last).setFillColor(sf::Color::Green);
}

void ColorText::isColorNum (DList<sf::Text>::iterator& last)
{
    (*last).setFillColor(sf::Color::Red);
}
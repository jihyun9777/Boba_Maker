#include "Label.h"

int Label::charSize = 25;

Label::Label()
{
    t.setFont(Fonts::getFonts());
    t.setCharacterSize(charSize);
    t.setFillColor(sf::Color::Black);
    t.setPosition(0.f,0.f);
}

void Label::setString(std::string label)
{
    t.setString(label);
}

void Label::setSize(int s)
{
    t.setCharacterSize(s);
}

void Label::setPosition(sf::Vector2f v)
{
    t.setPosition(v);
}

void Label::setColor(sf::Color c)
{
    t.setFillColor(c);
}

void Label::setOrigin(sf::Vector2f v)
{
    t.setOrigin(v);
}

float Label::getSize() const
{
    return t.getCharacterSize();
}

std::string Label::getString() const
{
    t.getString();
}

sf::FloatRect Label::getBound() const
{
    t.getGlobalBounds();
}

void Label::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(t);
}

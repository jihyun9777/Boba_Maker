#include "TextBox.h"

TextBox::TextBox()
{
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color{225, 200, 0, 200});
    box.setOutlineThickness(5);
}

void TextBox::setSize(sf::Vector2<float> v)
{
    box.setSize(v);
}

void TextBox::setColor(sf::Color c)
{
    box.setFillColor(c);
}

void TextBox::setOutlineColor(sf::Color c)
{
    box.setOutlineColor(c);
}

void TextBox::setPosition(sf::Vector2<float> v)
{
    box.setPosition(v);
}

sf::Vector2f TextBox::getPosition() const
{
    return box.getPosition();
}

sf::FloatRect TextBox::getBound() const
{
    return box.getGlobalBounds();
}

void TextBox::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
}
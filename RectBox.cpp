#include "RectBox.h"

RectBox::RectBox()
{
    box.setFillColor(sf::Color::White);
}

void RectBox::setSize(sf::Vector2<float> v)
{
    box.setSize(v);
}

void RectBox::setColor(sf::Color c)
{
    box.setFillColor(c);
}

void RectBox::setPosition(sf::Vector2<float> v)
{
    box.setPosition(v);
}

sf::Vector2f RectBox::getPosition() const
{
    return box.getPosition();
}

sf::FloatRect RectBox::getBound() const
{
    return box.getGlobalBounds();
}

void RectBox::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
}

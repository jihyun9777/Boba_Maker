#include "InputBox.h"

InputBox::InputBox()
{
    title.setString("MENU");
    title.setCharacterSize(25);
    title.setFillColor(sf::Color::Black);
    title.setFont(Fonts::getFonts());

    box.setSize(Item::boxSize);
}

void InputBox::setString (std::string s)
{
    title.setString(s);
    //setCenter();
}

void InputBox::setPosition(sf::Vector2f v)
{
    box.setPosition(v);
    //setCenter();
}

void InputBox::setStringPosition(sf::Vector2f v)
{
    title.setPosition(v);
}

void InputBox::setCenter()
{
    sf::FloatRect bounds = box.getBound();
    title.setOrigin({title.getGlobalBounds().width/2, title.getGlobalBounds().height/2});
    title.setPosition({bounds.left + bounds.width/2, bounds.top + bounds.height/2 - 5});
}

sf::Vector2f InputBox::getPosition() const
{
    return box.getPosition();
}

sf::FloatRect InputBox::getBound() const
{
    return box.getBound();
}

std::string InputBox::getString() const
{
    return title.getString();
}

void InputBox::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(title);
}

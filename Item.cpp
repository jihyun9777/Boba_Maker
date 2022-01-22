#include "Item.h"

sf::Vector2f Item::boxSize = {200, 45};

Item::Item()
{
    title.setString("Example");
    title.setFont(Fonts::getFonts());
    title.setCharacterSize(25);
    title.setFillColor(sf::Color::Black);
    box.setSize(boxSize);
    box.setPosition({5,200});
}

void Item::setString(std::string s)
{
    title.setString(s);
    //setCenter();
}

void Item::setPosition(sf::Vector2f v)
{
    box.setPosition(v);
    //setCenter();
}

void Item::setStringPosition(sf::Vector2f v)
{
    title.setPosition(v);
}

void Item::setCenter()
{
    sf::FloatRect bBounds = box.getBound();
    sf::FloatRect tBounds = title.getGlobalBounds();
    title.setOrigin({tBounds.left + tBounds.width/2, tBounds.top + tBounds.height/2});
    title.setPosition({bBounds.left + bBounds.width/2, bBounds.top + bBounds.height/2 - 15});
}

void Item::setSize(sf::Vector2f v)
{
    box.setSize(v);
}

void Item::setColor(sf::Color c)
{
    box.setColor(c);
}

sf::Vector2f Item::getPosition() const
{
    return box.getPosition();
}

std::string Item::getString() const
{
    return title.getString();
}

sf::FloatRect Item::getBound() const
{
    return box.getBound();
}

void Item::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect rect = getBound();
    if(MouseEvents<sf::FloatRect>::hovered(rect, window))
        enableState(HIGHLIGHT);
    else
        disableState(HIGHLIGHT);

    if(MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
        enableState(BUTTON);
    else
        disableState(BUTTON);
}

void Item::update()
{
    if(isEnabled(HIGHLIGHT))
        box.setColor(sf::Color::Green);
    else
        box.setColor(sf::Color::White);
}

void Item::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(title);
}


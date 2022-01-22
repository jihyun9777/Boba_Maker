#include "Menu.h"

Menu::Menu()
{
    top.setString("MENU");
}

void Menu::setString(std::string s)
{
    top.setString(s);
}

void Menu::addItem(std::string s)
{
    list.addItem(s);
}

void Menu::setPosition(sf::Vector2f v)
{
    top.setPosition(v);
    top.setStringPosition({v.x + 45, v.y + 10});
    list.setPosition({v.x + top.getBound().width, v.y});
}

sf::FloatRect Menu::getBound() const
{
    sf::FloatRect rect (top.getBound());
    rect.height += list.getSize() * rect.height;
    return rect;
}

void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //Show list when top is clicked
    sf::FloatRect rect (top.getBound());
    if (MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
    {
        top.enableState(CLICK);
        list.enableState(CLICK);
    }
    else if (MouseEvents<RectBox>::mouseClicked(window, event))
    {
        top.disableState(CLICK);
        list.disableState(CLICK);
    }

    //Change item color when hovered
    if (list.isEnabled(CLICK))
        list.addEventHandler(window, event);
}

void Menu::update()
{
    top.update();
    list.update();
}

void Menu::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(top);
    window.draw(list);
}
#include "Menubar.h"

sf::Vector2f MenuBar::menubarPos = {5, 500};

MenuBar::MenuBar()
{
    Menu m1;
    menuList.push_back(m1);
    setPosition(menubarPos);
}

void MenuBar::addMenu(std::string s)
{
    Menu m;
    m.setString(s);
    menuList.push_back(m);
}

void MenuBar::setPosition(sf::Vector2f v)
{
    for (int i = 0; i <= menuList.size(); i ++)
    {
        menuList[i].setPosition({v.x + i * menuList[i].getBound().width, v.y});
    }
}

int MenuBar::getSize() const
{
    return menuList.size();
}

void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    for (int i = 0; i < menuList.size(); i ++)
    {
        menuList[i].addEventHandler(window, event);
    }
}

void MenuBar::update()
{
    for (int i = 0; i < menuList.size(); i ++)
    {
        menuList[i].update();
    }
}

void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for (int i = 0; i < menuList.size(); i ++)
    {
        window.draw(menuList[i]);
    }
}

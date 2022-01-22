#include "ItemList.h"

ItemList::ItemList()
{}

void ItemList::addItem(std::string s)
{
    Item it;
    it.setString(s);
    items.push_back(it);
}

void ItemList::setPosition(sf::Vector2f v)
{
    if (!items.empty())
    {
        items[0].setPosition(v);
        items[0].setStringPosition({v.x + 10, v.y + 10});
        prevPos = {v};
    }
    for(int i = 1; i < items.size(); i ++)
    {
        prevPos.y += Item::boxSize.y;
        items[i].setPosition(prevPos);
        items[i].setStringPosition({prevPos.x + 10, prevPos.y + 10});
    }
}

void ItemList::setLastClick(std::string s)
{
    lastClick = s;
}

sf::FloatRect ItemList::getBound(int i) const
{
    return items.at(i).getBound();
}

sf::FloatRect ItemList::getBound() const
{
    sf::FloatRect bound = {0, 0, 0, 0};

    if(!items.empty())
        bound = items.at(0).getBound();

    for(int i = 1; i < items.size(); i ++)
        bound.height += items.at(i).getBound().height;

    return bound;
}

std::string ItemList::getString(int i) const
{
    return items.at(i).getString();
}

int ItemList::getSize() const
{
    return items.size();
}

std::string ItemList::getLastClick() const
{
    return lastClick;
}

void ItemList::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (isEnabled(CLICK))
            items.at(i).addEventHandler(window, event);

        sf::FloatRect rect = items.at(i).getBound();

        if (MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
        {
            setLastClick(items.at(i).getString());
            enableState(ITEMCLICK);
        }
    }
}

void ItemList::update()
{
    for(int i = 0; i < items.size(); i ++)
    {
        items.at(i).update();
    }
}

void ItemList::draw (sf::RenderTarget& window, sf::RenderStates states) const
{
    if (isEnabled(CLICK))
    {
        for (int i = 0; i < items.size(); i ++)
        {
            window.draw(items.at(i));
        }
    }
}

#include "DropdownMenu.h"

sf::Vector2f DropdownMenu::menuPos = {5,200};

sf::RectangleShape DropdownMenu::flavor;

sf::Sprite DropdownMenu::ice;

sf::Sprite DropdownMenu::topping;

DropdownMenu::DropdownMenu()
{
    menu.setPosition(menuPos);
    /*
    for (int i = 0; i < 5; i ++)
    {
        std::string s = std::to_string(i);
        list.addItem(s);
    }
    */
    list.setPosition({menuPos.x, menuPos.y + menu.getBound().height});
}

void DropdownMenu::setFavorite(ObjectStates size, ObjectStates flavor, ObjectStates topping, ObjectStates ice)
{
    enableState(size);
    enableState(flavor);
    enableState(topping);
    enableState(ice);
}

void DropdownMenu::resetLastClick()
{
    list.setLastClick("");
}

void DropdownMenu::reset()
{
    disableState(sizeState);
    disableState(flavorState);
    disableState(toppingState);
    disableState(iceState);
}

void DropdownMenu::setString(std::string s)
{
    menu.setString(s);
}

void DropdownMenu::setPosition(sf::Vector2f v)
{
    menu.setPosition(v);
    menu.setStringPosition({v.x + 45, v.y + 10});
    list.setPosition({v.x, v.y + menu.getBound().height - 5});
}

std::string DropdownMenu::getLastClick() const
{
    return lastClick;
}

void DropdownMenu::addItem(std::string s)
{
    list.addItem(s);
}

sf::FloatRect DropdownMenu::getBound()
{
    sf::FloatRect bound = menu.getBound();
    if(list.isEnabled(CLICK))
    {
        for(int i = 0; i < list.getSize(); i ++)
            bound.height += list.getBound(i).height;
    }
    return bound;
}

void DropdownMenu::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //Show list when menu is clicked
    sf::FloatRect rect = menu.getBound();
    if (MouseEvents<sf::FloatRect>::mouseClicked(rect, window))
        list.enableState(CLICK);
    else if (MouseEvents<RectBox>::mouseClicked(window, event))
        list.disableState(CLICK);

    list.addEventHandler(window, event);
    lastClick =  list.getLastClick();

    /*
    //Check cup size
    if(Shortcuts::isSmall(list.getLastClick()))
    {
        sizeState = SMALL;
        enableState(SMALL);
        enableState(sizeState);
    }
    else
        disableState(SMALL);
    if(Shortcuts::isMedium(list.getLastClick()))
    {
        sizeState = MEDIUM;
        enableState(sizeState);
        enableState(MEDIUM);
    }
    else
        disableState(MEDIUM);
    if(Shortcuts::isLarge(list.getLastClick()))
    {
        sizeState = LARGE;
        enableState(sizeState);
        enableState(LARGE);
    }
    else
        disableState(LARGE);

    //Check Flavor
    if(Shortcuts::isThai(list.getLastClick()) || isEnabled(THAI))
    {
        flavorState = THAI;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{225, 50, 0, 225});
    }
    if(Shortcuts::isMilk(list.getLastClick()) || isEnabled(MILK))
    {
        flavorState = MILK;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{50, 0, 0, 50});
    }
    if(Shortcuts::isGreen(list.getLastClick()) || isEnabled(GREEN))
    {
        flavorState = GREEN;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{0, 225, 0, 200});
    }
    if(Shortcuts::isTaro(list.getLastClick()) || isEnabled(TARO))
    {
        flavorState = TARO;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{150,0,225,225});
    }
    if(Shortcuts::isRed(list.getLastClick()) || isEnabled(RED))
    {
        flavorState = RED;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{100,0,0, 235});
    }
    if(Shortcuts::isStraw(list.getLastClick()) || isEnabled(STRAW))
    {
        flavorState = STRAW;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{225,0,0, 100});
    }
    if(Shortcuts::isBlue(list.getLastClick()) || isEnabled(BLUE))
    {
        flavorState = BLUE;
        enableState(flavorState);
        flavor.setFillColor(sf::Color{0,0,225, 200});
    }
    if(Shortcuts::isBanana(list.getLastClick()) || isEnabled(BANANA))
    {
        flavorState = BANANA;
        enableState(flavorState);
        flavor.setFillColor(sf::Color::Yellow);
    }
    if(Shortcuts::isWater(list.getLastClick()) || isEnabled(WATER))
    {
        flavorState = WATER;
        enableState(flavorState);
        flavor.setFillColor(sf::Color::Red);
    }

    //Check Topping
    if(Shortcuts::isBoba(list.getLastClick()) || isEnabled(BOBA))
    {
        toppingState = BOBA;
        enableState(toppingState);
        topping.setTexture(Image::getImage(Image::BOBA));
    }
    if(Shortcuts::isPearl(list.getLastClick()) || isEnabled(PEARL))
    {
        toppingState =PEARL;
        enableState(toppingState);
        topping.setTexture(Image::getImage(Image::PEARL));
    }
    if(Shortcuts::isAloe(list.getLastClick()) || isEnabled(ALOE))
    {
        toppingState = ALOE;
        enableState(toppingState);
        topping.setTexture(Image::getImage(Image::ALOE));
    }

    //Check Ice
    if(Shortcuts::isLess(list.getLastClick()) || isEnabled(LESS))
    {
        iceState = LESS;
        enableState(iceState);
        ice.setTexture(Image::getImage(Image::LESS));
    }
    if(Shortcuts::isRegul(list.getLastClick()) || isEnabled(REGUL))
    {
        iceState = REGUL;
        enableState(iceState);
        ice.setTexture(Image::getImage(Image::REGUL));
    }
    if(Shortcuts::isExtra(list.getLastClick()) || isEnabled(EXTRA))
    {
        iceState = EXTRA;
        enableState(iceState);
        ice.setTexture(Image::getImage(Image::EXTRA));
    }

    //Check Save
    if(Shortcuts::isImage(list.getLastClick()))
        enableState(CAPTURE);
    else
        disableState(CAPTURE);
    if(Shortcuts::isFavor(list.getLastClick()))
    {
        favorite.setFavorite(sizeState, flavorState, toppingState, iceState);
    }
    */
}

void DropdownMenu::update()
{
    list.update();
    if(list.isEnabled(ITEMCLICK))
    {
        menu.setString(list.getLastClick());
        list.disableState(ITEMCLICK);
    }
}

void DropdownMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    sf::Sprite s;
    s.setTexture(Image::getImage(Image::CUP));
/*
    if(isEnabled(SMALL))
    {
        //Draw Flavor
        if(isEnabled(flavorState))
        {
            flavor.setSize({280, 300});
            flavor.setPosition({545,400});
            window.draw(flavor);
            std::cout << "2";
        }

        //Draw Ice
        if(isEnabled(iceState))
        {
            ice.setScale({0.8,0.8});
            ice.setPosition({-80,70});
            window.draw(ice);
            std::cout << "3";
        }

        //Draw Topping
        if(isEnabled(toppingState))
        {
            topping.setScale({0.8,0.8});
            topping.setPosition({-80,80});
            window.draw(topping);
            std::cout << "4";
        }

        //Draw Cup
        if(isEnabled(sizeState))
        {
            s.setPosition({50, 150});
            s.setScale({0.65, 0.65});
            window.draw(s);
            std::cout << "1";
        }
    }
    if(isEnabled(MEDIUM))
    {
        //Draw Flavor
        flavor.setSize({300, 320});
        flavor.setPosition({535,380});
        window.draw(flavor);

        //Draw Ice
        ice.setScale({0.8,0.8});
        ice.setPosition({-80, 50});
        window.draw(ice);

        //Draw Topping
        topping.setScale({0.8,0.8});
        topping.setPosition({-80,80});
        window.draw(topping);

        //Draw Cup
        if(isEnabled(sizeState))
        {
            s.setPosition({0, 100});
            s.setScale({0.7, 0.7});
            window.draw(s);
        }
    }
    if(isEnabled(LARGE))
    {
        //Draw Flavor
        flavor.setSize({310, 330});
        flavor.setPosition({545,380});
        window.draw(flavor);

        //Draw Ice
        ice.setScale({0.83,0.83});
        ice.setPosition({-85, 40});
        window.draw(ice);

        //Draw Topping
        topping.setScale({0.83,0.83});
        topping.setPosition({-80,70});
        window.draw(topping);

        //Draw Cup
        if(isEnabled(sizeState))
        {
            s.setPosition({-25, 75});
            s.setScale({0.75, 0.75});
            window.draw(s);
        }
    }
*/

    window.draw(menu);
    window.draw(list);
}

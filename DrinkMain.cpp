#include "DrinkMain.h"

Favorite DrinkMain::favorite;
sf::Sprite DrinkMain::sizeImage;
sf::Sprite DrinkMain::toppingImage;
sf::Sprite DrinkMain::iceImage;
sf::RectangleShape DrinkMain::flavorImage;

DrinkMain::DrinkMain()
{
    sizeCost = 0;
    flavorCost = 0;
    toppingCost = 0;
    total = 0;

    rect.setSize({1000, 600});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({200, 200});

    logOut.setString("Log out");
    logOut.setPosition({1215, 700});
    logOut.setStringPosition({1220, 730});
    logOut.setSize({110, 100});

    pay.setString("Pay");
    pay.setPosition({1215, 550});
    pay.setStringPosition({1220, 580});
    pay.setSize({110, 100});

    a.setTexture(Image::getImage(Image::BOBA1));
    a.setScale({0.25, 0.25});
    a.setPosition({10, 5});
    b.setTexture(Image::getImage(Image::BOBA2));
    b.setScale({0.25, 0.25});
    b.setPosition({225, 5});
    c.setTexture(Image::getImage(Image::BOBA3));
    c.setScale({0.25, 0.25});
    c.setPosition({440, 5});
    d.setTexture(Image::getImage(Image::BOBA4));
    d.setScale({0.25, 0.25});
    d.setPosition({655, 5});
    e.setTexture(Image::getImage(Image::BOBA5));
    e.setScale({0.25, 0.25});
    e.setPosition({870, 5});

    size.setString("Size");
    size.addItem("Small");
    size.addItem("Medium");
    size.addItem("Large");
    size.setPosition({5, 5});

    flavor.setString("Flavor");
    flavor.addItem("Thai Tea");
    flavor.addItem("Milk Tea");
    flavor.addItem("Green Tea");
    flavor.addItem("Taro");
    flavor.addItem("Red Bean");
    flavor.addItem("Strawberry");
    flavor.addItem("Blueberry");
    flavor.addItem("Banana");
    flavor.addItem("Watermelon");

    topping.setString("Topping");
    topping.addItem("Boba");
    topping.addItem("Pearl");
    topping.addItem("Aloe");

    ice.setString("Ice");
    ice.addItem("No Ice");
    ice.addItem("Less Ice");
    ice.addItem("Regular Ice");
    ice.addItem("Extra Ice");

    save.setString("Save");
    save.addItem("Image");
    save.addItem("Favorite");

    flavor.setPosition({size.getBound().width + 10, 5});
    topping.setPosition({flavor.getBound().left + flavor.getBound().width + 10, 5});
    ice.setPosition({topping.getBound().left + topping.getBound().width + 10, 5});
    save.setPosition({ice.getBound().left + ice.getBound().width + 10, 5});

    sizeImage.setTexture(Image::getImage(Image::CUP));
}

void DrinkMain::reset()
{
    sizeCost = 0;
    flavorCost = 0;
    toppingCost = 0;
    total = 0;

    disableState(sizeState);
    disableState(flavorState);
    disableState(toppingState);
    disableState(iceState);

    sizeState = NOTHING;
    flavorState = NOTHING;
    toppingState = NOTHING;
    iceState = NOTHING;

    size.setString("Size");
    size.resetLastClick();
    flavor.setString("Flavor");
    flavor.resetLastClick();
    topping.setString("Topping");
    topping.resetLastClick();
    ice.setString("Ice");
    ice.resetLastClick();
    save.setString("Save");
    save.resetLastClick();
}

void DrinkMain::setFavorite(Favorite f)
{
    sizeState = f.getSize();
    flavorState = f.getFlavor();
    toppingState = f.getTopping();
    iceState = f.getIce();
}

Favorite DrinkMain::getFavorite()
{
    if(isEnabled(FAVORITE))
        return favorite;
}

void DrinkMain::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //Check cup size
    size.addEventHandler(window, event);
    if(Shortcuts::isSmall(size.getLastClick()) || sizeState == SMALL)
    {
        sizeState = SMALL;
        enableState(sizeState);
        enableState(SMALL);
        sizeCost = 4.25;
        s = "SMALL";
    }
    else
        disableState(SMALL);
    if(Shortcuts::isMedium(size.getLastClick()) || sizeState == MEDIUM)
    {
        sizeState = MEDIUM;
        enableState(sizeState);
        enableState(MEDIUM);
        sizeCost = 5.25;
        s = "MEDIUM";
    }
    else
        disableState(MEDIUM);
    if(Shortcuts::isLarge(size.getLastClick()) || sizeState == LARGE)
    {
        sizeState = LARGE;
        enableState(sizeState);
        enableState(LARGE);
        sizeCost = 6.25;
        s = "LARGE";
    }
    else
        disableState(LARGE);

    //Check Flavor
    flavor.addEventHandler(window, event);
    if(Shortcuts::isThai(flavor.getLastClick()) || flavorState == THAI)
    {
        flavorState = THAI;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{225, 50, 0, 225});
        f = "THAI TEA";
    }
    if(Shortcuts::isMilk(flavor.getLastClick()) || flavorState == MILK)
    {
        flavorState = MILK;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{50, 0, 0, 50});
        f = "MILK TEA";
    }
    if(Shortcuts::isGreen(flavor.getLastClick()) || flavorState == GREEN)
    {
        flavorState = GREEN;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{0, 225, 0, 200});
        f = "GREEN TEA";
    }
    if(Shortcuts::isTaro(flavor.getLastClick()) || flavorState == TARO)
    {
        flavorState = TARO;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{150,0,225,225});
        flavorCost = 1;
        f = "TARO";
    }
    if(Shortcuts::isRed(flavor.getLastClick()) || flavorState == RED)
    {
        flavorState = RED;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{100,0,0, 235});
        flavorCost = 1;
        f = "RED BEAN";
    }
    if(Shortcuts::isStraw(flavor.getLastClick()) || flavorState == STRAW)
    {
        flavorState = STRAW;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{225,0,0, 100});
        flavorCost = 1.25;
        f = "STRAWBERRY";
    }
    if(Shortcuts::isBlue(flavor.getLastClick()) || flavorState == BLUE)
    {
        flavorState = BLUE;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color{0,0,225, 200});
        flavorCost = 1.25;
        f = "BLUEBERRY";
    }
    if(Shortcuts::isBanana(flavor.getLastClick()) || flavorState == BANANA)
    {
        flavorState = BANANA;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color::Yellow);
        flavorCost = 1.25;
        f = "BANANA";
    }
    if(Shortcuts::isWater(flavor.getLastClick()) || flavorState == WATER)
    {
        flavorState = WATER;
        enableState(flavorState);
        flavorImage.setFillColor(sf::Color::Red);
        flavorCost = 1.25;
        f = "WATERMELON";
    }

    //Check Topping
    topping.addEventHandler(window, event);
    if(Shortcuts::isBoba(topping.getLastClick()) || toppingState == BOBA)
    {
        toppingState = BOBA;
        enableState(toppingState);
        toppingImage.setTexture(Image::getImage(Image::BOBA));
        toppingCost = 1.5;
        t = "BOBA";
    }
    if(Shortcuts::isPearl(topping.getLastClick()) || toppingState == PEARL)
    {
        toppingState = PEARL;
        enableState(toppingState);
        toppingImage.setTexture(Image::getImage(Image::PEARL));
        toppingCost = 1.5;
        t = "PEARL";
    }
    if(Shortcuts::isAloe(topping.getLastClick()) || toppingState == ALOE)
    {
        toppingState = ALOE;
        enableState(toppingState);
        toppingImage.setTexture(Image::getImage(Image::ALOE));
        toppingCost = 1.75;
        t = "ALOE";
    }

    //Check Ice
    ice.addEventHandler(window, event);
    if(ice.getLastClick() == "No Ice")
        i = "NO ICE";
    if(Shortcuts::isLess(ice.getLastClick()) || iceState == LESS)
    {
        iceState = LESS;
        enableState(iceState);
        iceImage.setTexture(Image::getImage(Image::LESS));
        i = "LESS ICE";
    }
    if(Shortcuts::isRegul(ice.getLastClick()) || iceState == REGUL)
    {
        iceState = REGUL;
        enableState(iceState);
        iceImage.setTexture(Image::getImage(Image::REGUL));
        i = "REGULAR ICE";
    }
    if(Shortcuts::isExtra(ice.getLastClick()) || iceState == EXTRA)
    {
        iceState = EXTRA;
        enableState(iceState);
        iceImage.setTexture(Image::getImage(Image::EXTRA));
        i = "EXTRA ICE";
    }
    total = sizeCost + flavorCost + toppingCost;

    //Check save
    save.addEventHandler(window, event);
    if(save.isEnabled(CAPTURE))
        enableState(CAPTURE);
    if(Shortcuts::isFavor(save.getLastClick()))
    {
        enableState(FAVORITE);
        favorite.setFavorite(sizeState, flavorState, toppingState, iceState);
    }

    logOut.addEventHandler(window, event);
    if(logOut.isEnabled(BUTTON))
        disableState(LOGIN);

    pay.addEventHandler(window, event);
    if(pay.isEnabled(BUTTON))
    {
        payment.setItem(s,f,t,i);
        payment.setCost(std::to_string(sizeCost), std::to_string(flavorCost),
                        std::to_string(toppingCost), std::to_string(total));
        payment.addEventHandler(window, event);
        if(payment.isEnabled(PAY))
            enableState(PAY);
    }
}

void DrinkMain::update()
{
    size.update();
    flavor.update();
    topping.update();
    ice.update();
    save.update();
    logOut.update();
    pay.update();
}

void DrinkMain::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
    window.draw(flavor);
    window.draw(topping);
    window.draw(ice);
    window.draw(save);
    window.draw(size);
    window.draw(a);
    window.draw(b);
    window.draw(c);
    window.draw(d);
    window.draw(e);
    window.draw(logOut);
    window.draw(pay);

    if(isEnabled(SMALL))
    {
        //Draw Flavor
        if(isEnabled(flavorState))
        {
            flavorImage.setSize({280, 300});
            flavorImage.setPosition({545,400});
            window.draw(flavorImage);
        }

        //Draw Ice
        if(isEnabled(iceState))
        {
            iceImage.setScale({0.8,0.8});
            iceImage.setPosition({-80,70});
            window.draw(iceImage);
        }

        //Draw Topping
        if(isEnabled(toppingState))
        {
            toppingImage.setScale({0.8,0.8});
            toppingImage.setPosition({-80,80});
            window.draw(toppingImage);
        }

        //Draw Cup
        if(isEnabled(sizeState))
        {
            sizeImage.setPosition({50, 150});
            sizeImage.setScale({0.65, 0.65});
            window.draw(sizeImage);
        }
    }
    if(isEnabled(MEDIUM))
    {
        //Draw Flavor
        if(isEnabled(flavorState))
        {
            flavorImage.setSize({300, 320});
            flavorImage.setPosition({535,380});
            window.draw(flavorImage);
        }

        //Draw Ice
        if(isEnabled(iceState))
        {
            iceImage.setScale({0.8,0.8});
            iceImage.setPosition({-80, 50});
            window.draw(iceImage);
        }

        //Draw Topping
        if(isEnabled(toppingState))
        {
            toppingImage.setScale({0.8,0.8});
            toppingImage.setPosition({-80,80});
            window.draw(toppingImage);
        }

        //Draw Cup
        if(isEnabled(sizeState))
        {
            sizeImage.setPosition({0, 100});
            sizeImage.setScale({0.7, 0.7});
            window.draw(sizeImage);
        }
    }
    if(isEnabled(LARGE))
    {
        //Draw Flavor
        if(isEnabled(flavorState))
        {
            flavorImage.setSize({310, 330});
            flavorImage.setPosition({545,380});
            window.draw(flavorImage);
        }

        //Draw Ice
        if(isEnabled(iceState))
        {
            iceImage.setScale({0.83,0.83});
            iceImage.setPosition({-85, 40});
            window.draw(iceImage);
        }

        //Draw Topping
        if(isEnabled(toppingState))
        {
            toppingImage.setScale({0.83,0.83});
            toppingImage.setPosition({-80,70});
            window.draw(toppingImage);
        }

        //Draw Cup
        if(isEnabled(sizeState))
        {
            sizeImage.setPosition({-25, 75});
            sizeImage.setScale({0.75, 0.75});
            window.draw(sizeImage);
        }
    }
}
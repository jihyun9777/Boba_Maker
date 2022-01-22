#include "Option.h"

Option::Option()
{
    rect.setSize({1000, 700});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({200,100});

    pic.setTexture(Image::getImage(Image::BOBASHOP));
    pic.setPosition({400,150});

    title.setTexture(Image::getImage(Image::TITLE));
    title.setPosition({550, 450});

    welcome.setFillColor(sf::Color::Black);
    welcome.setCharacterSize(50);
    welcome.setFont(Fonts::getFonts());
    welcome.setPosition({450, 550});

    create.setString("Make Boba");
    create.setPosition({580, 620});
    create.setStringPosition({585, 620});
    create.setSize({200, 40});

    favor.setString("My Favorite");
    favor.setPosition({580, 680});
    favor.setStringPosition({585,680});
    favor.setSize({200, 40});

    point.setString("My History");
    point.setPosition({580, 740});
    point.setStringPosition({585, 740});
    point.setSize({200, 40});
}

void Option::firstTime(std::string s)
{
    welcome.setString("Welcome, " + s + "!");
}

void Option::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    create.addEventHandler(window, event);
    favor.addEventHandler(window, event);
    point.addEventHandler(window, event);

    if(create.isEnabled(BUTTON))
        enableState(CREATE);
    if(favor.isEnabled(BUTTON))
        enableState(FAVORITE);
    if(point.isEnabled(BUTTON))
        enableState(HISTORY);
}

void Option::update()
{
    create.update();
    favor.update();
    point.update();
}

void Option::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
    window.draw(pic);
    window.draw(title);
    window.draw(welcome);
    window.draw(create);
    window.draw(favor);
    window.draw(point);
}
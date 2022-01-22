#include "LogIn.h"

LogIn::LogIn()
{
    rect.setSize({1000, 700});
    rect.setFillColor(sf::Color::White);
    rect.setPosition({200,100});

    pic.setTexture(Image::getImage(Image::BOBASHOP));
    pic.setPosition({400,150});

    title.setTexture(Image::getImage(Image::TITLE));
    title.setPosition({550, 450});

    button.setString("Log In");
    button.setPosition({920, 640});
    button.setStringPosition({930, 670});
    button.setSize({100, 100});

    warning.setFillColor(sf::Color::Red);
    warning.setCharacterSize(15);
    warning.setFont(Fonts::getFonts());
    warning.setPosition({500, 750});

    name.setPosition({500,600});

    number.setString("Phone Number: ");
    number.setPosition({500, 670});
}

void LogIn::reset()
{
    warning.setString("");
    name.reset();
    number.reset();
}

std::string LogIn::getName()
{
    return name.getString();
}

std::string LogIn::getNumber()
{
    return number.getString();
}

void LogIn::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    name.addEventHandler(window, event);
    number.addEventHandler(window, event);
    button.addEventHandler(window, event);

    if(button.isEnabled(BUTTON))
    {
        if (!name.isEmpty() && !number.isEmpty())
        {
            warning.setString("Successfully Saved");
            enableState(LOGIN);
        }
        else if (name.isEmpty() && !number.isEmpty())
            warning.setString("Please enter your name");
        else if (!name.isEmpty() && number.isEmpty())
            warning.setString("Please enter your phone number");
        else
            warning.setString("Please enter your name and phone number");
    }
}

void LogIn::update()
{
    name.update();
    number.update();
    button.update();
}

void LogIn::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
    window.draw(pic);
    window.draw(title);
    window.draw(name);
    window.draw(number);
    window.draw(button);
    window.draw(warning);
}

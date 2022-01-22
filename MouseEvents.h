#ifndef SFML_PROJECT_MOUSEEVENTS_H
#define SFML_PROJECT_MOUSEEVENTS_H
#include <iostream>
#include <SFML/Graphics.hpp>

template <class T>
class MouseEvents {
public:
    static bool mouseClicked(T& object, sf::RenderWindow& window)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            sf::FloatRect mouseRect = object;
            if (pos.x >= mouseRect.left && pos.x <= mouseRect.left + mouseRect.width)
                if (pos.y >= mouseRect.top && pos.y <= mouseRect.top + mouseRect.height)
                    return true;
        }
        return false;
    }

    static bool mouseClicked(sf::RenderWindow& window, sf::Event event)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return true;
        return false;
    }
    /*
    static bool mouseDoubleClicked()
    {
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            clock.restart();
            if (clock.getElapsedTime().asMilliseconds() < 500 && Mouse::isButtonPressed(Mouse::Left))
                return true;
        }
        return false;
    }

    static bool mouseTripleClicked()
    {
        if (mouseDoubleClicked())
        {
            clock.restart();
            if (clock.getElapsedTime().asMilliseconds() < 500 && Mouse::isButtonPressed(Mouse::Left))
                return true;
        }
        return false;
    }
    */

    static bool hovered(T& object, sf::RenderWindow& window)
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        sf::FloatRect rect = object;
        if (pos.x > rect.left && pos.x < rect.left + rect.width)
            if (pos.y > rect.top && pos.y < rect.top + rect.height)
                return true;
        return false;
    }

private:
    static sf::Clock clock;
    static int clinks;
    static void countClicks(sf::Event event);
};

#endif //SFML_PROJECT_MOUSEEVENTS_H

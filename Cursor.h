#ifndef SFML_PROJECT_CURSOR_H
#define SFML_PROJECT_CURSOR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUI.h"

class CursorEvents : public GUI {
public:
    CursorEvents();
    void setPosition(sf::Vector2f v);
    sf::Vector2f getPosition() const;
    void moveCursor (sf::Vector2f v);
    void blinkOn ();

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event){}
    virtual void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot(){}
    virtual void applySnapshot(const Snapshot& snapshot){}
private:
    sf::Clock clock;
    sf::RectangleShape line;
};
#endif //SFML_PROJECT_CURSOR_H

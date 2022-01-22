#ifndef SFML_PROJECT_GUI_H
#define SFML_PROJECT_GUI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"

class GUI : public EventHandler, public States, public SnapshotInterface, public sf::Drawable {
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};
#endif //SFML_PROJECT_GUI_H

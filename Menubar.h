#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUI.h"
#include "Menu.h"

class MenuBar : public GUI{
public:
    MenuBar();
    void addMenu(std::string s);
    void setPosition(sf::Vector2f v);
    int getSize() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::Vector2f menubarPos;
private:
    std::vector<Menu> menuList;
};


#endif //SFML_PROJECT_MENUBAR_H

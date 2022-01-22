#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H
#include "ItemList.h"

class Menu : public GUI{
public:
    Menu();
    void setString(std::string s);
    void addItem(std::string s);
    void setPosition(sf::Vector2f v);

    sf::FloatRect getBound() const;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}
private:
    Item top;
    ItemList list;
};


#endif //SFML_PROJECT_MENU_H

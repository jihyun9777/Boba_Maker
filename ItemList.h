#ifndef SFML_PROJECT_ITEMLIST_H
#define SFML_PROJECT_ITEMLIST_H
#include "Item.h"
#include "GUI.h"
#include "Shortcuts.h"
#include <vector>

class ItemList: public GUI{
public:
    ItemList();
    void addItem(std::string s);
    void setPosition(sf::Vector2f v);
    void setLastClick(std::string s);

    sf::FloatRect getBound(int i) const;
    sf::FloatRect getBound() const;
    std::string getString(int i) const;
    int getSize() const;
    std::string getLastClick() const;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

private:
    std::vector<Item> items;
    sf::Vector2f prevPos;
    std::string lastClick;
};


#endif //SFML_PROJECT_ITEMLIST_H

#ifndef SFML_PROJECT_DROPDOWNMENU_H
#define SFML_PROJECT_DROPDOWNMENU_H
#include "InputBox.h"
#include "ItemList.h"
#include "GUI.h"
#include "MouseEvents.h"
#include "Image.h"
#include "Favorite.h"

class DropdownMenu : public GUI{
public:
    DropdownMenu();

    void reset();
    void setFavorite(ObjectStates size, ObjectStates flavor, ObjectStates topping, ObjectStates ice);
    void resetLastClick();
    void setString(std::string s);
    void setPosition(sf::Vector2f v);
    std::string getLastClick() const;
    void addItem(std::string s);

    sf::FloatRect getBound();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::Vector2f menuPos;
    static sf::RectangleShape flavor;
    static sf::Sprite ice;
    static sf::Sprite topping;
private:
    std::string lastClick;
    Favorite favorite;
    ObjectStates sizeState, flavorState, toppingState, iceState;
    InputBox menu;
    ItemList list;
};


#endif //SFML_PROJECT_DROPDOWNMENU_H

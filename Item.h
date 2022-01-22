#ifndef SFML_PROJECT_ITEM_H
#define SFML_PROJECT_ITEM_H
#include "GUI.h"
#include "Fonts.h"
#include "RectBox.h"
#include "TextBox.h"
#include "MouseEvents.h"
#include "Shortcuts.h"

class Item : public GUI{
public:
    Item();
    void setString(std::string s);
    void setPosition(sf::Vector2f v);
    void setStringPosition(sf::Vector2f v);
    void setCenter();
    void setSize(sf::Vector2f v);
    void setColor(sf::Color c);

    sf::Vector2f getPosition() const;
    std::string getString() const;
    sf::FloatRect getBound() const;

    static sf::Vector2f boxSize;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}
private:
    TextBox box;
    sf::Text title;
};


#endif //SFML_PROJECT_ITEM_H

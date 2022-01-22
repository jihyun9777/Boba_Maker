#ifndef SFML_PROJECT_INPUTBOX_H
#define SFML_PROJECT_INPUTBOX_H
#include "RectBox.h"
#include "Item.h"
#include "Fonts.h"
#include "GUI.h"

class InputBox : public GUI{
public:
    InputBox();
    void setString (std::string s);
    void setPosition(sf::Vector2f v);
    void setStringPosition(sf::Vector2f v);
    void setCenter();

    sf::Vector2f getPosition() const;
    sf::FloatRect getBound() const;
    std::string getString() const;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) {}
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

private:
    sf::Text title;
    TextBox box;
};


#endif //SFML_PROJECT_INPUTBOX_H

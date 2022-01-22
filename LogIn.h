#ifndef SFML_PROJECT_LOGIN_H
#define SFML_PROJECT_LOGIN_H
#include "TextInput.h"
#include "Item.h"
#include "Image.h"

class LogIn : public GUI{
public:
    LogIn();

    void reset();
    std::string getName();
    std::string getNumber();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

private:
    sf::RectangleShape rect;
    sf::Sprite pic, title;
    Item button;
    sf::Text warning;
    TextInput name;
    TextInput number;
};


#endif //SFML_PROJECT_LOGIN_H

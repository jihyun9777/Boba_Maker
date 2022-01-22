#ifndef SFML_PROJECT_OPTION_H
#define SFML_PROJECT_OPTION_H
#include "Item.h"
#include "Image.h"

class Option : public GUI{
public:
    Option();

    void firstTime(std::string s);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}
private:
    sf::RectangleShape rect;
    sf::Sprite pic, title;
    Item create, favor, point;
    sf::Text welcome;
};


#endif //SFML_PROJECT_OPTION_H

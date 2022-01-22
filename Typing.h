#ifndef SFML_PROJECT_TYPING_H
#define SFML_PROJECT_TYPING_H
#include "GUI.h"
#include "Shortcuts.h"
#include "History.h"
#include "DList.h"
#include "MultiText.h"
#include "Fonts.h"

class Typing : public GUI{
public:
    Typing();

    void reset();
    void setPosition(sf::Vector2f v);
    sf::FloatRect getBound();
    std::string getString();
    bool isEmpty() const;

    virtual void addEventHandler (sf::RenderWindow& window, sf::Event event);
    virtual void update(){}
    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot){}
private:
    std::string s;
    sf::Text text;
    Snapshot snap;
    MultiText word;
};

#endif //SFML_PROJECT_TYPING_H

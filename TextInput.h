#ifndef SFML_PROJECT_TEXTINPUT_H
#define SFML_PROJECT_TEXTINPUT_H
#include <cstring>
#include "Label.h"
#include "TextBox.h"
#include "GUI.h"
#include "Cursor.h"
#include "MouseEvents.h"
#include "Typing.h"

class TextInput : public GUI {
public:
    TextInput();

    void reset();
    void setString(std::string s);
    void setPosition(sf::Vector2f v);
    std::string getString();
    bool isEmpty() const;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot(){}
    virtual void applySnapshot(const Snapshot& snapshot){}

private:
    Label label;
    TextBox box;
    CursorEvents c;
    Typing text;
};

#endif //SFML_PROJECT_TEXTINPUT_H

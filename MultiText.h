#ifndef SFML_PROJECT_MULTITEXT_H
#define SFML_PROJECT_MULTITEXT_H
#include "GUI.h"
#include "DList.h"
#include "Fonts.h"
#include "ColorText.h"
#include "Shortcuts.h"

class MultiText : public GUI {
public:
    MultiText();
    void addWord (std::string s);
    void removeWord ();

    DList<sf::Text>::iterator getBegin() const;
    DList<sf::Text>::iterator getEnd() const;

    sf::FloatRect getBound();

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static int newLine;
    static int gap;
    static int textSize;
private:
    DList<sf::Text> list;
    DList<sf::Text>::iterator start;
    DList<sf::Text>::iterator last;
    ColorText color;
    sf::Text t;
};


#endif //SFML_PROJECT_MULTITEXT_H

#ifndef SFML_PROJECT_DRINKTREE_H
#define SFML_PROJECT_DRINKTREE_H
#include "FileTree.h"
#include "Item.h"

class DrinkTree : public GUI{
public:
    DrinkTree();
    void addItem(std::string s, std::string f, std::string t, std::string i);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const {}
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::RenderWindow treeWindow;
private:
    FileTree tree;
    Item exit;
};


#endif //SFML_PROJECT_DRINKTREE_H

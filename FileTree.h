#ifndef SFML_PROJECT_FILETREE_H
#define SFML_PROJECT_FILETREE_H
#include "FileNode.h"

class FileTree : public GUI {
public:
    FileTree();
    void push(std::string parent, std::string item);
    sf::FloatRect getBound();
    void toggle();
    void setIcon();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::FloatRect rootBound;

private:
    FileNode* root;
    void push(FileNode*& root, std::string parent, std::string item);
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
};


#endif //SFML_PROJECT_FILETREE_H

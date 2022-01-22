#ifndef SFML_PROJECT_FILENODE_H
#define SFML_PROJECT_FILENODE_H
#include <vector>
#include "FileItem.h"

class FileNode : public GUI {
public:
    FileNode();
    FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    FileNode(std::string text, sf::Vector2f size, sf::Vector2f position);

    void setItem(const FileItem &data);
    void setString(const std::string s);
    FileItem& getItem();
    std::vector<FileNode*>& getChildren();
    sf::FloatRect getBound() const;
    bool isLeaf() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    typedef typename std::vector<FileNode*>::iterator iterator;
    iterator begin();
    iterator end();

private:
    FileItem item;
    std::vector<FileNode*> children;
    void toggleChlidren();
    void reposition() const;
};


#endif //SFML_PROJECT_FILENODE_H

#ifndef SFML_PROJECT_FILEITEM_H
#define SFML_PROJECT_FILEITEM_H
#include "GUI.h"
#include "Image.h"
#include "Label.h"
#include "RectBox.h"
#include "MouseEvents.h"

class FileItem : public GUI {
public:
    FileItem();
    FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    FileItem(std::string text, sf::Vector2f size, sf::Vector2f position);

    void setPosition(sf::Vector2f v);
    void iconInit();
    void setIcon(Image::image i);
    void setString(std::string s);
    sf::FloatRect getBound() const;
    sf::Vector2f getPosition() const;
    std::string getString() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::Vector2f boxSize;

private:
    sf::Sprite icon;
    RectBox box;
    Label title;
    std::string s;
};


#endif //SFML_PROJECT_FILEITEM_H

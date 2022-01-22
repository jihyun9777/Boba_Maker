#ifndef SFML_PROJECT_LABEL_H
#define SFML_PROJECT_LABEL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Label : public sf::Drawable{
public:
    Label();
    void setString(std::string label);
    void setSize(int s);
    void setPosition(sf::Vector2f v);
    void setColor(sf::Color c);
    void setOrigin(sf::Vector2f v);

    float getSize() const;
    std::string getString() const;
    sf::FloatRect getBound()const;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;

    static int charSize;
private:
    sf::Text t;
};
#endif //SFML_PROJECT_LABEL_H

#ifndef SFML_PROJECT_RECTBOX_H
#define SFML_PROJECT_RECTBOX_H
#include <iostream>
#include <SFML/Graphics.hpp>

class RectBox : public sf::Drawable{
public:
    RectBox();
    void setSize(sf::Vector2<float> v);
    void setColor(sf::Color c);
    void setPosition(sf::Vector2<float> v);

    sf::Vector2f getPosition() const;
    sf::FloatRect getBound() const;

    virtual void draw (sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::RectangleShape box;
};


#endif //SFML_PROJECT_RECTBOX_H

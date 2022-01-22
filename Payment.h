#ifndef SFML_PROJECT_PAYMENT_H
#define SFML_PROJECT_PAYMENT_H
#include "Item.h"
#include "Label.h"

class Payment : public GUI{
public:
    Payment();
    void setItem(std::string s, std::string f, std::string t, std::string i);
    void setCost(std::string s, std::string f, std::string t, std::string tot);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const {}
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update() {}
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    static sf::RenderWindow payment;
private:
    sf::RectangleShape line;
    Label size, flavor, topping, ice, total;
    Label sizeCost, flavorCost, toppingCost, totalCost;
    Item exit, pay;
};


#endif //SFML_PROJECT_PAYMENT_H

#ifndef SFML_PROJECT_DRINKMAIN_H
#define SFML_PROJECT_DRINKMAIN_H
#include "DropdownMenu.h"
#include "Favorite.h"
#include "Payment.h"

class DrinkMain : public GUI{
public:
    DrinkMain();

    void reset();
    void setFavorite(Favorite f);
    Favorite getFavorite();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot() {}
    virtual void applySnapshot(const Snapshot& snapshot) {}

    std::string s, f, t, i;
    static Favorite favorite;
    static sf::Sprite sizeImage, toppingImage, iceImage;
    static sf::RectangleShape flavorImage;
private:
    double sizeCost, flavorCost, toppingCost, total;
    sf::RectangleShape rect;
    Item logOut, pay;
    sf::Sprite a, b, c, d, e;
    //Favorite favorite;
    DropdownMenu size, flavor, topping, ice, save;
    ObjectStates sizeState, flavorState, toppingState, iceState;
    Payment payment;
};


#endif //SFML_PROJECT_DRINKMAIN_H

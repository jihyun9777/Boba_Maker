#ifndef SFML_PROJECT_FAVORITE_H
#define SFML_PROJECT_FAVORITE_H
#include "States.h"
#include "Shortcuts.h"

class Favorite : public States{
public:
    Favorite();
    void setFavorite(ObjectStates size, ObjectStates flavor, ObjectStates topping, ObjectStates ice);
    bool isEmpty();
    ObjectStates getSize();
    ObjectStates getFlavor();
    ObjectStates getTopping();
    ObjectStates getIce();

private:
    ObjectStates sizeState, flavorState, toppingState, iceState;
};


#endif //SFML_PROJECT_FAVORITE_H

#include "Favorite.h"

Favorite::Favorite()
{}

void Favorite::setFavorite(ObjectStates size, ObjectStates flavor, ObjectStates topping, ObjectStates ice)
{
    sizeState = size;
    flavorState = flavor;
    toppingState = topping;
    iceState = ice;
}

bool Favorite::isEmpty()
{
    if(Shortcuts::isAnySize(sizeState) || Shortcuts::isAnyFlavor(flavorState) || Shortcuts::isAnyTopping(toppingState)
        || Shortcuts::isAnyIce(iceState))
        return false;
    return true;
}

ObjectStates Favorite::getSize()
{
    return sizeState;
}

ObjectStates Favorite::getFlavor()
{
    return flavorState;
}

ObjectStates Favorite::getTopping()
{
    return toppingState;
}

ObjectStates Favorite::getIce()
{
    return iceState;
}

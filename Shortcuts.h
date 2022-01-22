#ifndef SFML_PROJECT_SHORTCUTS_H
#define SFML_PROJECT_SHORTCUTS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.h"

class Shortcuts {
public:
    static bool isUndo()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            return true;
        return false;
    }

    static bool isDelete()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) || sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
            return true;
        return false;
    }

    static bool isEnter()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            return true;
        return false;
    }

    static bool isWord(std::string s)
    {
        if (s == "int" || s == "char" || s == "double" || s == "float")
            return true;
        return false;
    }
    static bool isOper(sf::Text t)
    {
        std::string s = t.getString();
        if (s == "=" || s == "+" || s == "-" || s == "*" || s == "/" || s == "<" || s == ">")
            return true;
        return false;
    }

    static bool isNum(sf::Text t)
    {
        std::string s = t.getString();
        if (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6"
        || s == "7" || s == "8" || s == "9")
            return true;
        return false;
    }

    static bool isSmall(std::string s)
    {
        if(!s.compare("Small"))
            return true;
        return false;
    }

    static bool isMedium(std::string s)
    {
        if(!s.compare("Medium"))
            return true;
        return false;
    }

    static bool isLarge(std::string s)
    {
        if(!s.compare("Large"))
            return true;
        return false;
    }

    static bool isThai(std::string s)
    {
        if(!s.compare("Thai Tea"))
            return true;
        return false;
    }

    static bool isMilk(std::string s)
    {
        if(!s.compare("Milk Tea"))
            return true;
        return false;
    }

    static bool isGreen(std::string s)
    {
        if(!s.compare("Green Tea"))
            return true;
        return false;
    }

    static bool isTaro(std::string s)
    {
        if(!s.compare("Taro"))
            return true;
        return false;
    }

    static bool isRed(std::string s)
    {
        if(!s.compare("Red Bean"))
            return true;
        return false;
    }

    static bool isStraw(std::string s)
    {
        if(!s.compare("Strawberry"))
            return true;
        return false;
    }

    static bool isBlue(std::string s)
    {
        if(!s.compare("Blueberry"))
            return true;
        return false;
    }

    static bool isBanana(std::string s)
    {
        if(!s.compare("Banana"))
            return true;
        return false;
    }

    static bool isWater(std::string s)
    {
        if(!s.compare("Watermelon"))
            return true;
        return false;
    }

    static bool isLess(std::string s)
    {
        if(!s.compare("Less Ice"))
            return true;
        return false;
    }

    static bool isRegul(std::string s)
    {
        if(!s.compare("Regular Ice"))
            return true;
        return false;
    }

    static bool isExtra(std::string s)
    {
        if(!s.compare("Extra Ice"))
            return true;
        return false;
    }

    static bool isBoba(std::string s)
    {
        if(!s.compare("Boba"))
            return true;
        return false;
    }

    static bool isPearl(std::string s)
    {
        if(!s.compare("Pearl"))
            return true;
        return false;
    }

    static bool isAloe(std::string s)
    {
        if(!s.compare("Aloe"))
            return true;
        return false;
    }

    static bool isImage(std::string s)
    {
        if(!s.compare("Image"))
            return true;
        return false;
    }

    static bool isFavor(std::string s)
    {
        if(!s.compare("Favorite"))
            return true;
        return false;
    }

    static bool isAnySize(ObjectStates size)
    {
        if(size != SMALL && size != MEDIUM && size != LARGE)
            return false;
        return true;
    }

    static bool isAnyFlavor(ObjectStates flavor)
    {
        if(flavor != THAI && flavor != MILK && flavor != GREEN && flavor != TARO && flavor != RED
         && flavor != STRAW && flavor != BLUE && flavor != BANANA && flavor != WATER)
            return false;
        return true;
    }

    static bool isAnyTopping(ObjectStates topping)
    {
        if(topping != BOBA && topping != PEARL && topping != ALOE)
            return false;
        return true;
    }

    static bool isAnyIce(ObjectStates ice)
    {
        if(ice != LESS && ice != REGUL && ice != EXTRA)
            return false;
        return true;
    }
};


#endif //SFML_PROJECT_SHORTCUTS_H

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

enum ObjectStates {ROOTCLICK, SHOWCHILD, HIGHLIGHT, ITEMCLICK, CLICK, NEWLINE, BLINK, BLINKON, TYPE, ENTERED,
                    SIZE, FLAVOR, TOPPING, ICE, NOTHING,
                    SMALL, MEDIUM, LARGE, CAPTURE, LOGIN, BUTTON, CREATE, FAVORITE, PAY, HISTORY,
                    THAI, MILK, GREEN, TARO, RED, STRAW, BLUE, BANANA, WATER,
                    BOBA, PEARL, ALOE, LESS, REGUL, EXTRA, LASTSTATE};

class States {
public:
    States();
    bool isEnabled (ObjectStates state) const;
    void enableState (ObjectStates state);
    void disableState (ObjectStates state);

private:
    std::map<ObjectStates, bool> states;
};

#endif //SFML_PROJECT_STATES_H

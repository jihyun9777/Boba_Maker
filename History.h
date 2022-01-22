#ifndef SFML_PROJECT_HISTORY_H
#define SFML_PROJECT_HISTORY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Stack.h"
#include "GUI.h"

class History {
public:
    static void pushHistory(const Snapshot& snapshot);

    static Snapshot& topHistory();

    static void popHistory();
    /*
    static void pushHistory(const Snapshot& snapshot) {stack.Push(snapshot);}

    static Snapshot& topHistory() {return stack.Top();}

    static void popHistory() {stack.Pop();}
    */
    //static void addEventHandler(sf::RenderWindow& window, sf::Event event) {}
private:
    static Stack<Snapshot> stack;
};

#endif //SFML_PROJECT_HISTORY_H

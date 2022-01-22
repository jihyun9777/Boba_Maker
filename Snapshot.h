#ifndef SFML_PROJECT_SNAPSHOT_H
#define SFML_PROJECT_SNAPSHOT_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Snapshot {
public:
    Snapshot() {}

    Snapshot(std::string item) {s = item;}

    void addSnap (std::string snap) {s = snap;}

    std::string getString () {return s;}
private:
    std::string s;
};
#endif //SFML_PROJECT_SNAPSHOT_H

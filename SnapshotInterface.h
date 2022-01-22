#ifndef SFML_PROJECT_SNAPSHOTINTERFACE_H
#define SFML_PROJECT_SNAPSHOTINTERFACE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snapshot.h"

class SnapshotInterface {
public:
    virtual Snapshot &getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot &snapshot) = 0;
};
#endif //SFML_PROJECT_SNAPSHOTINTERFACE_H

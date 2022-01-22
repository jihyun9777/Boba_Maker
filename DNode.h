#ifndef SFML_PROJECT_DNODE_H
#define SFML_PROJECT_DNODE_H
#include <iostream>

using namespace std;

template <class T>
class DNode
{
public:
    DNode()
    {
        _item = T();
        next = nullptr;
        prev = nullptr;
    }

    DNode(const T& item)
    {
        _item = item;
        next = nullptr;
        prev = nullptr;
    }

    T _item;
    DNode* next;
    DNode* prev;
};

#endif //SFML_PROJECT_DNODE_H

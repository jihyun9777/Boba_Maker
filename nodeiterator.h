#ifndef NODEITERATOR_H
#define NODEITERATOR_H
#include <iostream>
#include <iterator>
#include "dnode.h"

using namespace std;

template <class T>
class NodeIterator : public iterator<forward_iterator_tag, T>
{
public:
    NodeIterator();
    NodeIterator(DNode<T>* node);
    NodeIterator(const NodeIterator& iter);
    NodeIterator& operator =(const NodeIterator<T>& RHS);

    T& operator *() const;
    T& operator [](const NodeIterator<T>& LHS) const;

    NodeIterator& operator ++();    //prefix
    //NodeIterator operator ++(T);    //postfix
    NodeIterator& operator --();    //prefix
    //NodeIterator operator --(T);    //postfix

    NodeIterator& operator +=(int index);
    NodeIterator& operator -=(int index);
    NodeIterator& operator [](int index);

    template <class U>
    friend NodeIterator& operator +(const NodeIterator<U>& LHS, int index);
    template <class U>
    friend NodeIterator& operator -(const NodeIterator<U>& LHS, int index);

    template <class U>
    friend bool operator == (const NodeIterator<U>& LHS, const NodeIterator<U>& RHS);
    template <class U>
    friend bool operator != (const NodeIterator<U>& LHS, const NodeIterator<U>& RHS);

private:
    DNode<T>* current;
};

template <class T>
NodeIterator<T>::NodeIterator()
{
    current = nullptr;
}

template <class T>
NodeIterator<T>::NodeIterator(DNode<T>* node)
{
    current = node;
}

template <class T>
NodeIterator<T>::NodeIterator(const NodeIterator& iter)
{
    current = iter.current;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator =(const NodeIterator<T>& RHS)
{
    current = RHS.current;
}

template <class T>
T& NodeIterator<T>::operator *() const
{
    return current->_item;
}

template <class T>
T& NodeIterator<T>::operator [](const NodeIterator<T>& LHS) const
{
    return current->_item;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator ++()
{
    current = current->next;
    return *this;
}
/*
template <class T>
NodeIterator<T> NodeIterator<T>::operator ++(T)
{
    NodeIterator<T> temp = current;
    current = current->next;
    return temp;
}
*/
template <class T>
NodeIterator<T>& NodeIterator<T>::operator --()
{
    current = current->prev;
    return *this;
}
/*
template <class T>
NodeIterator<T> NodeIterator<T>::operator --(T)
{
    NodeIterator<T> temp = current;
    current = current->prev;
    return temp;
}
*/
template <class T>
NodeIterator<T>& NodeIterator<T>::operator +=(int index)
{
    for (int i = 0; i < index; i++)
    {
        if(current != nullptr)
            current = current->next;
    }
    return *this;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator -=(int index)
{
    for (int i = 0; i < index; i++)
    {
        if(current != nullptr)
            current = current->prev;
    }
    return *this;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator [](int index)
{
    for (int i = 0; i < index; i ++)
    {
        if (current == nullptr)
            break;
        current = current->next;
    }
    return *this;
}

template <class U>
NodeIterator<U>& operator +(const NodeIterator<U>& LHS, int index)
{
    NodeIterator<U> temp(LHS);
    for (int i = 0; i < index; i++)
    {
        if(temp.current != nullptr)
            temp.current = temp.current->next;
    }
    return temp;
}

template <class U>
NodeIterator<U>& operator -(const NodeIterator<U>& LHS, int index)
{
    NodeIterator<U> temp(LHS);
    for (int i = 0; i < index; i++)
    {
        if(temp.current != nullptr)
            temp.current = temp.current->prev;
    }
    return temp;
}

template <class U>
bool operator == (const NodeIterator<U>& LHS, const NodeIterator<U>& RHS)
{
    return LHS.current == RHS.current;
}

template <class U>
bool operator != (const NodeIterator<U>& LHS, const NodeIterator<U>& RHS)
{
    return LHS.current != RHS.current;
}

#endif // NODEITERATOR_H

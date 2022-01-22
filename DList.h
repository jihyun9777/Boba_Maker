#ifndef SFML_PROJECT_DLIST_H
#define SFML_PROJECT_DLIST_H
#include <iostream>
#include "DNode.h"
#include "nodeiterator.h"

using namespace std;

template <class T>
class DList
{
public:
    DList();
    ~DList();
    DList(const DList<T> &copyThis);
    DList& operator =(const DList& RHS);

    DNode<T>* InsertHead(T item);
    DNode<T>* InsertTail(T item);
    DNode<T>* InsertBefore(DNode<T>*& beforeThis, T item);
    DNode<T>* InsertAfter(DNode<T>*& afterThis, T item);
    DNode<T>* FindThis(T item);
    DNode<T>* GetHead() const;
    DNode<T>* GetTail() const;

    T RemoveHead();
    T RemoveTail();
    T RemoveNode(DNode<T>* deleteThis);
    void RemoveThis(T item);
    bool empty();
    int size() const;
    void ClearList();
    DNode<T>* CopyList(DNode<T>*& copyThis);
    DList& operator += (T item);

    template <class U>
    friend ostream& operator <<(ostream& outs, const DList<U>& printMe);

    typedef NodeIterator<T> iterator;

    iterator begin() const;
    iterator end() const;
    iterator last();
private:
    DNode<T>* head;
    DNode<T>* tail;
};

template <class T>
DList<T>::DList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
DList<T>::~DList()
{
    ClearList();
}

template <class T>
DList<T>::DList(const DList<T> &copyThis)
{
    head = CopyList(copyThis.head);
    tail = copyThis.tail;
}

template <class T>
DList<T>& DList<T>::operator =(const DList& RHS)
{
    if (head == RHS.head)
    {
        return *this;
    }
    else
    {
        ClearList();
        head = CopyList(RHS.head);
        tail = RHS.tail;
        return *this;
    }
}

template <class T>
DNode<T>* DList<T>::InsertHead(T item)
{
    DNode<T>* temp;
    temp = new DNode<T> (item);

    if (empty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}

template <class T>
DNode<T>* DList<T>::InsertTail(T item)
{
    DNode<T>* temp;
    temp = new DNode<T> (item);

    if (empty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    return tail;
}

template <class T>
DNode<T>* DList<T>::InsertBefore(DNode<T>*& beforeThis, T item)
{
    if (beforeThis == head)
        return insertHead(item);

    DNode<T>* temp;
    temp = new DNode<T> (item);
    beforeThis->prev->next = temp;
    temp->prev = beforeThis->prev->next;
    beforeThis->prev = temp;
    temp->next = beforeThis;

    return head;
}

template <class T>
DNode<T>* DList<T>::InsertAfter(DNode<T>*& afterThis, T item)
{
    if (afterThis == tail)
        return insertTail(item);

    DNode<T>* temp;
    temp = new DNode<T> (item);
    afterThis->next->prev = temp;
    temp->next = afterThis->next->prev;
    afterThis->next = temp;
    temp->prev = afterThis;

    return head;
}

template <class T>
DNode<T>* DList<T>::FindThis(T item)
{
    DNode<T>* walker = head;
    while(walker != nullptr)
    {
        if (walker->_item == item)
            return walker;
        walker = walker->next;
    }
    return nullptr;
}

template <class T>
DNode<T>* DList<T>::GetHead() const
{
    return head;
}

template <class T>
DNode<T>* DList<T>::GetTail() const
{
    return tail;
}

template <typename T>
T DList<T>::RemoveHead()
{
    if (head != nullptr)
    {
        T item = head->_item;
        DNode<T>* temp = head;

        //One node in the list
        if(head == tail)
            tail = nullptr;
        //More than one node in the list
        else
            head->next->prev = nullptr;

        head = head->next;
        delete temp;
        return item;
    }
}

template <class T>
T DList<T>::RemoveTail()
{
    if (tail != nullptr)
    {
        T item = tail->_item;
        DNode<T>* temp = tail;

        if (tail == head)
            head = nullptr;
        else
            tail->prev->next = nullptr;

        tail = tail->prev;
        delete temp;
        return item;
    }
}

template <class T>
T DList<T>::RemoveNode(DNode<T>* deleteThis)
{
    if (deleteThis != nullptr)
    {
        if (deleteThis == head)
            return RemoveHead();
        else if (deleteThis == tail)
            return RemoveTail();
        else
        {
            T item = deleteThis->_item;
            DNode<T>* temp = deleteThis;
            deleteThis->prev->next = deleteThis->next;
            deleteThis->next->prev = deleteThis->prev;
            delete temp;
            return item;
        }
    }
}

template <class T>
void DList<T>::RemoveThis(T item)
{
    DNode<T>* temp = FindThis(item);
    if (temp != nullptr)
        RemoveNode (temp);
}

template <class T>
bool DList<T>::empty()
{
    if (head == nullptr && tail == nullptr)
        return true;
    return false;
}

template <class T>
int DList<T>::size() const
{
    int counter = 0;
    DNode<T>* walker = head;
    while(walker != nullptr)
    {
        ++counter;
        walker = walker->next;
    }
    return counter;
}

template <class T>
void DList<T>::ClearList()
{
    while (head != nullptr)
    {
        RemoveHead();
    }
}

template <class T>
DNode<T>* DList<T>::CopyList(DNode<T>*& copyThis)
{
    if (copyThis == nullptr)
        return copyThis;

    while (copyThis != nullptr)
        copyThis = InsertTail (copyThis->_item);

    return head;
}

template <class T>
DList<T>& DList<T>::operator += (T item)
{
    intsertTail(item);
    return *this;
}

template <class U>
ostream& operator <<(ostream& outs, const DList<U>& printMe)
{
    DNode<U>* walker = printMe.head;

    while(walker != nullptr)
    {
        outs << walker->_item;
        walker = walker->next;
    }
    return outs;
}

template <class T>
typename DList<T>::iterator DList<T>::begin() const
{
    return NodeIterator<T>(head);
}

template <class T>
typename DList<T>::iterator DList<T>::end() const
{
    return NodeIterator<T>(nullptr);
}

template <class T>
typename DList<T>::iterator DList<T>::last()
{
    return NodeIterator<T>(tail);
}
#endif //SFML_PROJECT_DLIST_H

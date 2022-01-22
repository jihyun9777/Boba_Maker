#ifndef SFML_PROJECT_STACK_H
#define SFML_PROJECT_STACK_H
#include <iostream>
#include "DList.h"

using namespace std;

template <class T>
class Stack
{
public:
    Stack() {}
    ~Stack();
    Stack(const Stack<T> &copyThis);
    Stack& operator =(const Stack& RHS);

    DNode<T>* Push(T item);
    T Pop();
    bool empty();
    T& Top() const;
    int size() const;
    T seek(int index);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const Stack<U> &S);
private:
    DList<T> list;
};

template <class T>
Stack<T>::~Stack()
{
    list.ClearList();
}

template <class T>
Stack<T>::Stack(const Stack<T> &copyThis)
{
    list.CopyList(copyThis.list.GetHead());
}

template <class T>
Stack<T>& Stack<T>::operator =(const Stack& RHS)
{
    if (list.GetHead() == RHS.list.GetHead())
        return *this;
    else
    {
        list.ClearList();
        list.CopyList(RHS.list.GetHead());
        return *this;
    }
}

template <class T>
DNode<T>* Stack<T>::Push(T item)
{
    list.InsertHead(item);
}

template <class T>
T Stack<T>::Pop()
{
    if (!empty())
        list.RemoveHead();
}

template <class T>
bool Stack<T>::empty()
{
    return list.empty();
}

template <class T>
T& Stack<T>::Top() const
{
    return list.GetHead()->_item;
}

template <class T>
int Stack<T>::size() const
{
    return list.size();
}

template <class T>
T Stack<T>::seek(int index)
{
    if (index <= list.size())
    {
        DNode<T>* walker = list.GetHead();
        for (int i = 0; i < index; i ++)
        {
            walker = walker->next;
        }
    }
}

template <typename U>
ostream& operator <<(ostream& outs, const Stack<U> &S)
{
    outs << S.list;
    return outs;
}

#endif //SFML_PROJECT_STACK_H

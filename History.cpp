#include "History.h"

Stack<Snapshot> History::stack;

void History::pushHistory(const Snapshot& snapshot)
{
    stack.Push(snapshot);
}

Snapshot& History::topHistory()
{
    return stack.Top();
}

void History::popHistory()
{
    stack.Pop();
}


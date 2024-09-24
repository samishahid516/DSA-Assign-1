#include <iostream>
#include <stdexcept>

template <class ItemType>
class Stack 
{
private:
    ItemType* items;
    int capacity;
    int top;

public:
    Stack();
    ~Stack();
    void push(const ItemType& element);
    void pop();
    ItemType Top() const;
    bool IsEmpty() const;
    bool IsFull() const;
};

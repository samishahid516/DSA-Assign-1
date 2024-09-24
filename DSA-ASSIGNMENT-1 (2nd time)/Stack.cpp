#include "Stack.h"

template <class ItemType>
Stack<ItemType>::Stack()
{
    capacity = 50;
    top = -1;
    items = new ItemType[capacity];
}

template <class ItemType>
Stack<ItemType>::~Stack() 
{
    delete[] items;
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType& element) 
{
    if (IsFull()) 
    {
        throw std::overflow_error("Stack is full");
    }
    top++;
    items[top] = element;
}

template <class ItemType>
void Stack<ItemType>::pop()
{
    if (IsEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    top--;
}

template <class ItemType>
ItemType Stack<ItemType>::Top() const
{
    if (IsEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return items[top];
}

template <class ItemType>
bool Stack<ItemType>::IsEmpty() const 
{
    if (top == -1)
    {
        return true;
    }
    else
        return false;
}

template <class ItemType>
bool Stack<ItemType>::IsFull() const
{
    if (top == capacity - 1)
    {
        return true;
    }
    else
        return false;
}

template class Stack<char>;

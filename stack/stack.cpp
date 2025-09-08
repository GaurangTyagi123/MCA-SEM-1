#include "stack.h"

// Stack with array implementation
template <class T>
Stack<T>::Stack(size_t max) : top(-1), max(max)
{
    this->data = new T[max];
}

template <class T>
bool Stack<T>::isFull()
{
    return top == max - 1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template <class T>
void Stack<T>::push(T val)
{
    if (!isFull())
    {
        data[++top] = val;
    }
    else
    {
        std::cout << "OVERFLOW" << std::endl;
    }
}

template <class T>
void Stack<T>::pop()
{
    if (!isEmpty() && top != 0)
    {
        --top;
    }
    else if (top == 0)
    {
        top = -1;
    }
    else
    {
        std::cout << "UNDERFLOW" << std::endl;
    }
}

template <class T>
void Stack<T>::displayStack()
{
    if (!isEmpty())
    {
        size_t iter = top;
        while (iter != -1)
        {
            std::cout << data[iter--] << std::endl;
        }
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;
    }
}

//. stack with linked list
template <class T>
LStack<T>::LStack() {
    this->top = nullptr;
}

template <class T>
bool LStack<T>::isFull()
{
    StackNode<T> *temp = new StackNode<T>();
    return temp == nullptr;
}

template <class T>
bool LStack<T>::isEmpty()
{
    return this->top == nullptr;
}

template <class T>
void LStack<T>::push(T val)
{
    if (!isFull())
    {
        StackNode<T> *temp = new StackNode<T>();
        temp->data = val;
        temp->next = this->top;
        this->top = temp;
    }
    else
    {
        std::cout << "OVERFLOW" << std::endl;
    }
}

template <class T>
void LStack<T>::pop()
{
    if (!isEmpty() && top->next)
    {
        StackNode<T> *delNode = this->top;
        this->top = delNode->next;
        delete delNode;
    }
    else if (!top->next)
    {
        delete top;
        this->top = nullptr;
    }
    else
    {
        std::cout << "UNDERFLOW" << std::endl;
    }
}

template <class T>
void LStack<T>::displayStack()
{
    if (!isEmpty())
    {
        StackNode<T> *iter = this->top;
        while (iter)
        {
            std::cout << iter->data << std::endl;
            iter = iter->next;
        }
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;
    }
}
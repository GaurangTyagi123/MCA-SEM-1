#ifndef STACK_H
#define STACK_H
#include <cstddef>

template <class T>
class Stack
{
private:
    int top;
    size_t max;
    T *data;

public:
    Stack(size_t);
    bool isEmpty();
    bool isFull();
    void push(T);
    void pop();
    void displayStack();
};

template <class T>
struct StackNode
{
    T data;
    StackNode<T> *next;
};

template <class T>
class LStack
{
private:
    StackNode<T> *top;
public:
    LStack();
    bool isEmpty();
    bool isFull();
    void push(T val);
    void pop();
    void displayStack();
};

#endif
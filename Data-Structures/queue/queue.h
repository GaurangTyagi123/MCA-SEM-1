#ifndef QUEUE_H
#define QUEUE_H
#include <cstddef>

template <class T>
class Queue
{
private:
    int front;
    int rear;
    size_t max;
    T *data;

public:
    Queue(size_t);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(T val);
    T dequeue();
    void displayQueue();
};

template <class T>
struct QueueNode{
    T val;
    QueueNode<T> *next;
};

template <class T>
class LQueue{
    private:
        QueueNode<T> *front;
        QueueNode<T> *rear;
    public:
        LQueue();
        ~LQueue();
        bool isEmpty();
        bool isFull();
        void enqueue(T val);
        T dequeue();
        void displayQueue();
};

#endif

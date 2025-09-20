#include "queue.h"
#include <cstddef>

// . Queue using array
template <class T>
Queue<T>::Queue(size_t max) : front(-1), rear(-1), max(max)
{
    data = new T[max];
}

template <class T>
Queue<T>::~Queue()
{
    delete[] data;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return front == -1 && rear == -1;
}

template <class T>
bool Queue<T>::isFull()
{
    return (rear + 1) % max == front;
}

template <class T>
void Queue<T>::enqueue(T val)
{
    if (isEmpty())
    {
        rear = (rear + 1) % max;
        front = rear;
        data[rear] = val;
    }
    else if (!isFull())
    {
        rear = (rear + 1) % max;
        data[rear] = val;
    }
    else
    {
        std::cout << "Queue is full" << std::endl;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if (!isEmpty())
    {
        T temp = data[front];
        front = (front + 1) % max;
        return temp;
    }
    else
    {
        std::cout << "Queue is empty" << std::endl;
        return 100000;
    }
}

template <class T>
void Queue<T>::displayQueue()
{
    if (!isEmpty())
    {
        for (size_t i = front; i <= rear; i++)
        {
            std::cout << data[i] << " - ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Queue is empty" << std::endl;
}
// . Queue with Linked List
template <class T>
LQueue<T>::LQueue()
{
    front = nullptr;
    rear = nullptr;
}

template <class T>
LQueue<T>::~LQueue()
{
    delete front;
    delete rear;
}

template <class T>
bool LQueue<T>::isEmpty()
{
    return front == nullptr && rear == nullptr;
}

template <class T>
bool LQueue<T>::isFull()
{
    QueueNode<T>* temp = new QueueNode<T>();
    return temp == nullptr;
}

template <class T>
void LQueue<T>::enqueue(T val)
{
    if (isEmpty())
    {
        QueueNode<T>* temp = new QueueNode<T>();
        temp->val = val;
        temp->next = nullptr;

        rear = temp;
        front = temp;
    }
    else if (!isFull())
    {
        QueueNode<T>* temp = new QueueNode<T>();
        temp->val = val;
        temp->next = nullptr;
        rear->next = temp;
        rear = temp;
    }
    else
    {
        std::cout << "Queue is full" << std::endl;
    }
}

template <class T>
T LQueue<T>::dequeue()
{
    if(!isEmpty() && !this->front->next){
        T temp = front->val;
        QueueNode<T>* delNode = front;
        front = nullptr;
        rear = nullptr;
        delete delNode;
        return temp;
    }
    else if (!isEmpty() && this->front->next)
    {
        T temp = front->val;
        QueueNode<T>* delNode = front;
        front = delNode->next;
        delete delNode;
        return temp;
    }
    else
    {
        std::cout << "Queue is empty" << std::endl;
        return 100000;
    }
}

template <class T>
void LQueue<T>::displayQueue()
{
    if (!isEmpty())
    {
        QueueNode<T>* iter = front;
        while (iter)
        {
            std::cout << iter->val << " - ";
            iter = iter->next;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Queue is empty" << std::endl;
}
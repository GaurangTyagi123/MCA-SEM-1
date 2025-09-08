#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>

template <class T>
class Array
{
private:
    T *data;
    size_t capacity;
    size_t len;

public:
    Array(size_t initial_capacity=2);
    ~Array();
    T &operator[](size_t) const;
    size_t size() const;
    void displayList();

    void push_back(T);
    void pop(size_t);
    void insertAt(size_t,T val);
};

#endif
#include <cstddef>
#include "array.h"
#include <stdexcept>

template <class T>
Array<T>::Array(size_t initial_capacity)
{
    this->capacity = initial_capacity;
    this->len = 0;
    this->data = new T[capacity]();
}

template <class T>
Array<T>::~Array()
{
    delete[] data;
}

template <class T>
void Array<T>::push_back(T val)
{
    if (len == capacity)
    {
        this->capacity = capacity * 2;
        T *temp = new T[capacity];
        for (size_t i = 0; i < this->capacity; i++)
        {
            temp[i] = (*this)[i];
        }
        temp[len++] = val;
        this->data = temp;
    }
    else
    {
        data[len++] = val;
    }
}

template <class T>
T &Array<T>::operator[](size_t index) const
{
    if (index >= capacity)
        throw std::out_of_range("Index out of range");
    else
    {
        return data[index];
    }
}

template <class T>
void Array<T>::pop(size_t index)
{
    if (len != 0)
    {
        for (int i = index; i < len - 1; i++)
        {
            (*this)[i] = (*this)[i + 1];
        }
        this->len = len - 1;
    }
    else
    {
        throw std::out_of_range("Index out of bounds");
    }
}

template <class T>
void Array<T>::insertAt(size_t index, T val)
{
    if (index > len)
        throw std::out_of_range("Index out of range");
    else
    {
        data[len++] = val;
        for (int i = len - 1; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = val;
    }
}

template <class T>
void Array<T>::displayList()
{
    if (len == 0)
        std::cout << "The list is empyt" << std::endl;
    else
    {
        for(int i = 0u; i < len; i++)
        {
            std::cout << (*this)[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

template <class T>
size_t Array<T>::size() const
{
    return this->len;
}
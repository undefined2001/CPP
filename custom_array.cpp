#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
class custom_array
{
    T *list;
    int size;
    int capacity;

public:
    custom_array();
    ~custom_array();
    int get_size();
    void push_back(T);
    T pop_back();
    T at(int);
    bool is_full();
    void resize(int n = 0);
    int get_capacity();
    void print_list();
};

template <typename T>
custom_array<T>::custom_array()
{
    this->size = 0;
    this->capacity = 5;
    this->list = new T[this->capacity];
}

template <typename T>
custom_array<T>::~custom_array()
{
    delete[] this->list;
}

template <typename T>
T custom_array<T>::at(int idx)
{
    if (idx < size)
    {
        return this->list[idx];
    }
    else
    {
        throw std::out_of_range("List index out of Range");
    }
}

template <typename T>
int custom_array<T>::get_size()
{
    return this->size;
}

template <typename T>
void custom_array<T>::push_back(T data)
{
    if (is_full())
    {
        resize();
    }

    this->list[this->size] = data;
    size++;
}

template <typename T>
int custom_array<T>::get_capacity()
{
    return this->capacity;
}

template <typename T>
T custom_array<T>::pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("List is empty");
    }

    T popval = this->list[size - 1];
    size--;
    return popval;
}

template <typename T>
bool custom_array<T>::is_full()
{
    return size == capacity;
}

template <typename T>
void custom_array<T>::resize(int n)

{
    int newCapacity;
    if (n)
    {
        newCapacity = n;
    }
    else
    {
        newCapacity = capacity * 2;
    }
    T *newList = new T[newCapacity];
    std::memcpy(newList, list, size * sizeof(T));
    delete[] list;
    list = newList;
    capacity = newCapacity;
}

template <typename T>
void custom_array<T>::print_list()
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->list[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    custom_array<int> list;
    for (int i = 100; i < 1200; i += 100)
    {
        list.push_back(i);
    }

    list.print_list();
    list.resize(40);
    std::cout << list.get_capacity() << std::endl;

    return 0;
}

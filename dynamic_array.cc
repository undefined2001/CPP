#include <iostream>

template <typename _Tp, int _capacity>
class list
{
private:
    int size;
    int capacity;

public:
    class iterator
    {
        _Tp *ptr;

    public:
        iterator(_Tp *_ptr) : ptr(_ptr) {};
        bool operator==(const iterator &other) { return ptr == other.ptr; }
        bool operator!=(const iterator &other) { return ptr != other.ptr; }

        _Tp &operator*() { return *ptr; }
        iterator &operator++()
        {
            ++ptr;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ptr++;
            return temp;
        }
    };

public:
    _Tp *array;
    list();
    list(std::initializer_list<_Tp> init);
    ~list();
    typename list<_Tp, _capacity>::iterator begin()
    {
        return iterator(array);
    }
    typename list<_Tp, _capacity>::iterator end()
    {
        return iterator((array + size));
    }
};

template <typename _Tp, int _capacity>
list<_Tp, _capacity>::list() : array(new _Tp[_capacity]), size(0), capacity(_capacity)
{
}

template <typename _Tp, int _capacity>
list<_Tp, _capacity>::list(std::initializer_list<_Tp> init) : array(new _Tp[_capacity]), size(0), capacity(_capacity)
{
    for (typename std::initializer_list<_Tp>::iterator it = init.begin(); it != init.end(); it++)
    {

        array[size++] = *it;
    }
}

template <typename _Tp, int _capacity>
list<_Tp, _capacity>::~list()
{
    delete[] this->array;
}

int main()
{
    list<int, 5> my_list = {1, 2, 3, 4, 5};
    for (list<int, 5>::iterator it = my_list.begin(); it != my_list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
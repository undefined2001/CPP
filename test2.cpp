#include <iostream>

class Array
{
private:
    int *data;
    int size;
    int len;

public:
    Array() : data(nullptr), size(0), len(0) {}

    Array(int size) : data(new int[size]), size(size), len(0) {}

    // Copy constructor (deep copy)
    Array(const Array &other) : size(other.size), len(other.len)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator (deep copy)
    Array &operator=(const Array &other)
    {
        if (this == &other) return *this; // self-assignment check

        delete[] data;

        size = other.size;
        len = other.len;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    int length() const { return size; }

    int at(int idx) const { return data[idx]; }

    void add(int idx, int a) { data[idx] = a; }

    ~Array()
    {
        delete[] data;
        data = nullptr;
        size = 0;
        len = 0;
    }
};

int main()
{
    Array a(5);
    for (int i = 0; i < a.length(); i++)
    {
        a.add(i, i * i);
    }

    Array b = a; // deep copy happens here
    b.add(3, 100);

    std::cout << "Printing A array" << std::endl; 
    for (int i = 0; i < a.length(); i++)
    {
        std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Printing B Array" << std::endl;
    for (int i = 0; i < b.length(); i++)
    {
        std::cout << b.at(i) << " ";
    }
    std::cout << std::endl;
}

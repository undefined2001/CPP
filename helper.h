#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <vector>

std::vector<std::string> split(std::string mystr, std::string splitter)
{
    std::vector<std::string> finalarr;
    std::string substr;
    for (size_t i = 0; i < mystr.length(); i++)
    {
        if (mystr.substr(i, splitter.length()) == splitter)
        {
            finalarr.push_back(substr);
            substr.clear();
            i += splitter.length() - 1;
        }
        else
        {
            substr.push_back(mystr[i]);
        }
    }
    finalarr.push_back(substr);
    return finalarr;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

template <typename T>
void print_array(T *arr, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            std::cout << arr[i];
        }
        else
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "]" << std::endl;
}

#endif

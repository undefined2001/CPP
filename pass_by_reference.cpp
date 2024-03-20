#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5;
    int y = 7;
    std::cout << "Before Swap:"
              << "A: " << x << ", "
              << "B: " << y << std::endl;
    swap(x, y);
    std::cout << "After Swap:"
              << "A: " << x << ", "
              << "B: " << y << std::endl;
    return 0;
}
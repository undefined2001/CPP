#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 5;
    int b = 6;
    std::cout << "Before Swap:"
              << "A: " << a << ", "
              << "B: " << b << std::endl;
    swap(&a, &b);
    std::cout << "After Swap:"
              << "A: " << a << ", "
              << "B: " << b << std::endl;

    return 0;
}
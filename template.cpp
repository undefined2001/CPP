#include <iostream>

template <typename... T>
void GPIO_Init(T... pins)
{
    int tempReg = 0;
    ((tempReg |= (1 << pins)),...);
    std::cout << tempReg << std::endl;
}

int main()
{

    GPIO_Init(1, 2, 3);
    return 0;
}
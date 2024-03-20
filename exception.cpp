#include <iostream>

int main()
{
    int a = 5;
    char b = 'h';

    try
    {
        std::cout << (a + b) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
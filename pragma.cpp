// Pragma directly can send command to the compiler
#pragma pack(1)
#include <iostream>

struct Test
{
    int num;
    char grade;
};

int main()
{

    size_t c = sizeof(struct Test);

    std::cout << c << std::endl;

    return 0;
}

/**
 * since we are using the pragma pack(1) we are telling the compiler to align the byte by byte instead of word by word
 * which is default for the compiler
*/
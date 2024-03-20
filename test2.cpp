#include <iostream>
#include <stdint.h>

int main()
{
    uint8_t name[] = {0x41, 0x72, 0x69, 0x66, 0x61};
    uint8_t *name_ptr = name;
    uint8_t size = sizeof(name) / sizeof(name[0]);

    while (size--)
    {
        std::cout << (char)*name_ptr++;
    }
    std::cout << std::endl;
    return 0;
}
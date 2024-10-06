#include <iostream>
#include <cstdint>

int main()
{
    char a = 'A';

    char *ptr = &a;

    char *&new_ptr = ptr;

    return 0;
}

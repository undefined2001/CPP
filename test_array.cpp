#include <iostream>
#include "helper.h"

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::string new_arr[5] = {
        "Asraful",
        "Islam",
        "Taj"};
    print_array(arr, size);
    print_array(new_arr, 3);

    return 0;
}
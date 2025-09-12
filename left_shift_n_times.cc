#include <iostream>
#include <vector>
#include "helper.h"

void reverse_array(std::vector<int> &vec)
{
    int start{0}, end{static_cast<int>(vec.size()) - 1};
    std::cout << start << "   " << end << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {5, 10, 15, 20, 30};
    reverse_array(vec);
}
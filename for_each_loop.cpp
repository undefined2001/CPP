#include <iostream>
int main()
{
    int info[5] = {1, 2, 3, 4, 5};
    for (int item : info)
    {
        std::cout<<item<<std::endl;
    }
    return 0;
}
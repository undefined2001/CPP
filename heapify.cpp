#include <iostream>

void min_heapify(int arr[], int size, int index)
{
    int smallest = index;
    int left_child = index * 2;
    int right_child = index * 2 + 1;
    if (arr[left_child] < arr[smallest] && left_child <= size)
    {
        smallest = left_child;
    }
    if (arr[right_child] < arr[smallest] && right_child <= size)
    {
        smallest = right_child;
    }
    if (smallest != index && index <= size)
    {
        std::swap(arr[smallest], arr[index]);
        min_heapify(arr, size, index);
    }
}

int main()
{

    int arr[6] = {-1, 50, 40, 30, 20, 10};
    
    for (int i = 5 / 2 ; i > 0; i--)
    {
        min_heapify(arr, 5, i);
    }
    for (int i = 1; i <= 5; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
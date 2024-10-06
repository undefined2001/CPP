#include <iostream>

void rotate_right(int *arr, int size)
{
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int sequence[6] = {10, 20, 30, 40, 50, 60};
    int beats[6] = {1, 0, 0, 1, 0, 1};
    int size = 6;

    for (int i = 0; i < size; i++)
    {
        if (beats[i])
        {
            rotate_right(sequence, size);
        }
    }

    print_arr(sequence, size);

    return 0;
}
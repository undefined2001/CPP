#include <iostream>
using namespace std;
void rightShiftToNplace(int arr[], int size, int n)
{
    int index = n % size;
    int newArr[index];

    // Coping Data
    int a = size - index, b = 0;
    while (a < size)
    {
        newArr[b] = arr[a];
        a++;
        b++;
    }
    // Shifting to Right
    for (int j = size - 1; j >= 0; j--)
    {
        arr[j + index] = arr[j];
    }

    // Marging Value
    for (int k = 0; k < index; k++)
    {
        arr[k] = newArr[k];
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    rightShiftToNplace(arr, size, 12);
    // rightShiftToNplace(arr, size, 2);
    display(arr, size);
}
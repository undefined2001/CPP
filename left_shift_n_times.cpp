#include <iostream>
using namespace std;
void leftShiftNtime(int arr[], int size, int n)
{
    int index = n % size;
    int newArr[index];
    // Copying data
    for (int i = 0; i < index; i++)
    {
        newArr[i] = arr[i];
    }
    // Shifting Left
    for (int j = index; j < size; j++)
    {
        arr[j - index] = arr[j];
    }
    int l = 0;
    // Marging Copied data into old array
    for (int k = size - index; k < size; k++)
    {
        arr[k] = newArr[l];
        l++;
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
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    leftShiftNtime(arr, size, 20);
    display(arr, size);

    return 0;
}
#include <iostream>
using namespace std;
void insert(int arr[], int index, int value, int *size, int maxSize)
{
    if (*size == maxSize)
    {
        cout << "No Space Left" << endl;
    }
    else if (index < 0 || index > maxSize)
    {

        cout << "Invalid Index" << endl;
    }
    for (int i = *size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
    (*size) += 1;
}
void display(int arr[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 5};

    int size = 5;

    int maxSize = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSize<<endl;

    display(arr, &size);

    insert(arr, 3, 300, &size, 20);

    display(arr, &size);

    return 0;
}
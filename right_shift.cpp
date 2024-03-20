#include <iostream>
using namespace std;
void rightShift(int arr[], int size, int len)
{
    int temp = arr[size-1];
    for (int i = size - 1; i >= 1; i--)
    {

        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {10, 20, 50, 40, 60};

    display(arr, 5);

    rightShift(arr,5,5);
    rightShift(arr,5,5);

    display(arr, 5);



    return 0;
}
#include <iostream>
using namespace std;
void leftShift(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 1; i < size ; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[size - 1] = temp;
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
    int arr[10] = {15, 10, 5, 20, 60};
    leftShift(arr, 5);
    leftShift(arr, 5);
    display(arr, 5);



    return 0;

}
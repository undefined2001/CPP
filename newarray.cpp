#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int arr[], int size)
{
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int min(int arr[], int size)
{
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int main()
{

    int arr[6] = {1, 2, 3, -1, 40, 5};

    int arraySize = sizeof(arr) / sizeof(arr[0]);

    // printArray(arr, arraySize);

    cout <<"Max Value: "<< max(arr, arraySize) << endl;
    cout <<"Min Value: "<< min(arr, arraySize) << endl;

    // Maximum and Minimum Element in a Array
}
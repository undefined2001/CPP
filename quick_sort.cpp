#include <bits/stdc++.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapBitwise(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

/*
This Function is for dividing the array into two subarray where
the left side of pivot is lower than pivot and the right side is greater than pivot
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pindex = 0;
    int i = 0;
    while (i < high)
    {
        if (arr[i] < pivot)
        {
            // Swaping index with pindex if the value of arr[i] < pivot
            swap(&arr[pindex], &arr[i]);
            pindex++;
        }
        i++;
    }
    swap(&arr[high], &arr[pindex]);
    std::cout << pindex << std::endl;
    return pindex;
}

void quickSort(int arr[], int low, int high)
{
    // This is the base condition of exiting this QuickSort Function
    if (low >= high)
    {
        return;
    }
    // in this variable we are storing the index where out pivot is after partitioning
    int partionIndex = partition(arr, low, high);
    quickSort(arr, low, partionIndex - 1);
    quickSort(arr, partionIndex + 1, high);
}

// This is an Utility function to print a Array

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int arr[6] = {30, 25, 40, 50, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}
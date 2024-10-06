#include <bits/stdc++.h>

/*
This Function is for comparing two sub array and merging them into
one new sorted array and finally return the array
*/
void merge(int arr[], int left, int middle, int right)
{
    int temparray[right];
    int i = left, j = middle + 1, k = left;

    /*
    This loop will continue until one of two array is ended
    To be specific the smallest one also the sorting part is
    happening inside this loop
    */
    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temparray[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temparray[k] = arr[j];
            k++;
            j++;
        }
    }

    /*
    loop will continue if the left array is greater and there are some value left
    */
    while (i <= middle)
    {
        temparray[k] = arr[i];
        i++;
        k++;
    }

    /*
    loop will continue if the right array is greater and there are some value left
    */
    while (j <= right)
    {
        temparray[k] = arr[j];
        j++;
        k++;
    }
    // This is for copying the elements form temporary sorted array to the permanet one
    for (int count = left; count <= right; count++)
    {
        arr[count] = temparray[count];
    }
}

// This function calling the margeSort Algorithm Recursively

void megreSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = (left + right) / 2;
    megreSort(arr, left, middle);
    megreSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
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
    int size;
    std::cout << "Enter the Number of Elements You Want: ";
    std::cin >> size;
    // int arr[size] = {30, 25, 40, 50, 10, 5};
    int arr[size];
    std::cout << "Enter the Elements separated by space: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Before Sort: \n";
    printArray(arr, size);
    megreSort(arr, 0, size - 1);
    std::cout << "After Sort: \n";
    printArray(arr, size);
}
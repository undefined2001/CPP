#include <iostream>
#include <cstdlib>
#include <algorithm>

struct Node
{
    int item;
    int weight;
    int value;

    friend std::ostream &operator<<(std::ostream &out, Node &n)
    {
        out << "Item: " << n.item << ", Weight: " << n.weight << ", Value: " << n.value << std::endl;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Node &n)
    {
        in >> n.item >> n.weight >> n.value;
        return in;
    }
};

void merge(Node *arr, int left, int middle, int right)
{
    Node temp_arr[right - left + 1];
    int i = 0, j = middle - left + 1, k = 0;

    while (i <= middle - left && j <= right - left)
    {
        if (arr[left + i].value >= arr[left + j].value)
        {
            temp_arr[k] = arr[left + i];
            i++;
        }
        else
        {
            temp_arr[k] = arr[left + j];
            j++;
        }
        k++;
    }

    while (i <= middle - left)
    {
        temp_arr[k] = arr[left + i];
        i++;
        k++;
    }

    while (j <= right - left)
    {
        temp_arr[k] = arr[left + j];
        j++;
        k++;
    }

    for (int count = 0; count <= right - left; count++)
    {
        arr[left + count] = temp_arr[count];
    }
}

void merge_sort(Node *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int *knapsack(Node *arr, int size)
{
    int temp_arr[size + 1];
    
    int res_arr[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp_arr[arr[i].item] = arr[i].value / arr[i].weight;
    }
    std::sort(temp_arr + 1, temp_arr + size + 1, std::greater<int>());
    for (int j = 0; j <= size; j++)
    {
        rest
    }
}

void print_arr(Node *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    std::size_t size;
    std::cin >> size;
    Node arr[size];
    Node n;
    for (std::size_t i = 0; i < size; i++)
    {
        std::cin >> n;
        arr[i] = n;
    }
    std::cout << "Before Sort: " << std::endl;
    print_arr(arr, size);
    // std::cout << "After Sort: " << std::endl;
    // merge_sort(arr, 0, size - 1);
    int length = sizeof(arr) / sizeof(arr[0]);
    knapsack(arr, length);
    // print_arr(arr, size);

    return 0;
}
#include <iostream>
#include <climits>

template <typename T_Data>
class Heap
{
    int size;
    T_Data *arr;

public:
    Heap(int);
    void push(T_Data);
    T_Data pop();
    void peek();
    void showHeap();
};

template <typename T_Data>
Heap<T_Data>::Heap(int n) : arr(new int[n + 1]), size(0){};

template <typename T_Data>
void Heap<T_Data>::push(T_Data data)
{
    ++size;
    arr[size] = data;
    int index = size;
    while (index > 1)
    {
        int parent = index / 2;
        if (arr[index] > arr[parent])
        {
            std::swap(arr[index], arr[parent]);
            index = parent;
        }
        else
        {
            return;
        }
    }
}

template <typename T_Data>
T_Data Heap<T_Data>::pop()
{
    if (size < 1)
    {
        return INT_MIN;
    }
    int rm_val = arr[1];
    arr[1] = arr[size];
    size--;
    int index = 1;
    while (index < size)
    {
        int left_child = index * 2;
        int right_child = index * 2 + 1;
        if (arr[index] < arr[left_child])
        {
            std::swap(arr[index], arr[left_child]);
            index = left_child;
        }
        else if (arr[index] < arr[right_child])
        {
            std::swap(arr[index], arr[right_child]);
            index = right_child;
        }
        else
        {
            break;
        }
    }
    return rm_val;
}

template <typename T_Data>
void Heap<T_Data>::showHeap()
{
    for (int i = 1; i <= this->size; i++)
    {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Heap<int> h(10);
    h.push(10);
    h.push(20);
    h.push(300);
    h.push(400);
    std::cout << "Before Removing: ";
    h.showHeap();
    std::cout << "Popped the top value: " << h.pop() << std::endl;
    std::cout << "Popped the top value: " << h.pop() << std::endl;
    std::cout << "After Removing: ";
    h.showHeap();

    return 0;
}
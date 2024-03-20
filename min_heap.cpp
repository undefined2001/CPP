#include <bits/stdc++.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Heap
{
    int *heaparr;
    int heapSize;
    int capacity;

public:
    Heap(int);
    int getSize();
    void insertMinHeap(int);
    int extractMin();
    void minHeapify(int);
    int linearSearch(int);
    int height();
    int parent(int);
    int leftChild(int);
    int rightChild(int);
    void printHeap();
    void decreaseKey(int, int);
    void deleteKey(int i);
    int *heapsort(int);
};
Heap::Heap(int size)
{
    heapSize = 0;

    capacity = size;
    heaparr = new int[capacity];
}

int Heap::parent(int index)
{
    return (index - 1) / 2;
}

int Heap::leftChild(int i)
{
    return (i * 2) + 1;
}

int Heap::rightChild(int i)
{
    return (i * 2) + 2;
}

void Heap::insertMinHeap(int val)
{
    if (heapSize == capacity)
    {
        std::cout << "Heap is Full" << std::endl;
        return;
    }
    heapSize++;
    int i = heapSize - 1;
    heaparr[i] = val;
    while (heaparr[i] != 0 && heaparr[i] < heaparr[parent(i)])
    {
        swap(&heaparr[parent(i)], &heaparr[i]);

        i = parent(i);
    }
}

int Heap::linearSearch(int val)
{
    for (int i = 0; i < heapSize; i++)
    {
        if (heaparr[i] == val)
        {
            return heaparr[i];
        }
    }
    return -1;
}

int Heap::getSize()
{
    return heapSize;
}

int Heap::height()
{
    return ceil(log2(heapSize + 1)) - 1;
}

int Heap::extractMin()
{
    if (heapSize <= 0)
    {
        return INT_MAX;
    }
    else if (heapSize == 1)
    {
        heapSize--;
        return heaparr[0];
    }
    else
    {
        int root = heaparr[0];
        heaparr[0] = heaparr[heapSize - 1];
        heapSize--;
        minHeapify(0);
        return root;
    }
}

void Heap::minHeapify(int i)
{
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heapSize && heaparr[l] < heaparr[smallest])
    {
        smallest = l;
    }
    else if (r < heapSize && heaparr[r] < heaparr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&heaparr[smallest], &heaparr[i]);
        minHeapify(smallest);
    }
}
void Heap::decreaseKey(int i, int val)
{
    heaparr[i] = val;
    while (i != 0 && heaparr[i] < heaparr[parent(i)])
    {
        swap(&heaparr[i], &heaparr[parent(i)]);
        i = parent(i);
    }
}

int *Heap::heapsort(int size)
{
    int i = 0;
    int *temp = new int[size];
    while (i < size)
    {
        // std::cout << size << std::endl;
        temp[i] = extractMin();
        i++;
    }
    return temp;
}

void Heap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void Heap::printHeap()
{
    for (int i = 0; i < heapSize; i++)
    {
        std::cout << heaparr[i] << " ";
    }
}

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Heap heap(10);
    heap.insertMinHeap(5);
    heap.insertMinHeap(2);
    heap.insertMinHeap(10);
    heap.insertMinHeap(1);
    heap.printHeap();
    std::cout << std::endl;
    // heap.extractMin();
    // heap.deleteKey(1);
    // heap.printHeap();
    int size = heap.getSize();
    int *newarr = heap.heapsort(heap.getSize());
    std::cout << size << std::endl;
    printarray(newarr, size);
    return 0;
}
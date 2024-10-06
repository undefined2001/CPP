#include <iostream>
#include <vector>

struct Node
{
    int item;
    int weight;
    int value;

    // Node(int i, int w, int v)
    // {
    //     item = i;
    //     weight = w;
    //     value = v;
    // }

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

void merge(std::vector<Node *>, int start, int end)
{
}

void merge_sort(std::vector<Node *> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid);
    }
}

void print(std::vector<Node *> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << *arr.at(i) << std::endl;
    }
}
int main()
{
    std::vector<Node *> arr;
    for (int i = 0; i < 5; i++)
    {
        Node *n = new Node();
        std::cin >> *n;
        arr.push_back(n);
    }
    print(arr);
    return 0;
}
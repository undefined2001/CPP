#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int> &vec, vector<int> &left, vector<int> &right)
{
    int i{0}, j{0}, k{0};
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            vec[k++] = left[i++];
        }
        else
        {
            vec[k++] = right[j++];
        }
    }
    while (i < left.size())
    {
        vec[k++] = left[i++];
    }
    while (j < right.size())
    {
        vec[k++] = right[j++];
    }
}

void merge_sort(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        return;
    }
    
    int mid = vec.size() / 2;

    vector<int> left(vec.begin(), vec.begin() + mid);
    vector<int> right(vec.begin() + mid, vec.end());

    merge_sort(left);
    merge_sort(right);

    merge(vec, left, right);
}

void print_vector(vector<int> &vec)
{
    for (int elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> vec = {100, 50, 90, 70, 60};
    merge_sort(vec);
    print_vector(vec);

    return 0;
}
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int> &vec, int start, int mid, int end)
{
    // Temporary arrays
    vector<int> left(vec.begin() + start, vec.begin() + mid + 1);
    vector<int> right(vec.begin() + mid + 1, vec.begin() + end + 1);

    int i = 0, j = 0, k = start;

    // Merge the two halves
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] <= right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

    // Copy leftovers
    while (i < (int)left.size())
        vec[k++] = left[i++];

    while (j < (int)right.size())
        vec[k++] = right[j++];
}

void merge_sort(vector<int> &vec, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);
    merge(vec, start, mid, end);
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    merge_sort(arr, 0, arr.size() - 1);

    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

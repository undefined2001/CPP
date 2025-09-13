#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &vec, int start, int mid, int end)
{
    vector<int> left(vec.begin() + start, vec.begin() + mid + 1);
    vector<int> right(vec.begin() + mid, vec.begin() + end + 1);

    int i = 0, j = 0, k = start;

    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] <= right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

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
    vector<int> vec = {90, 80, 70, 75, 100};

    merge_sort(vec, 0, vec.size() - 1); // inclusive end

    for (int i : vec)
        cout << i << " ";
    cout << endl;
}

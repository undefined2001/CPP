#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int> &vec, vector<int> &left, vector<int> &right)
{
    vec.resize((left.size() + right.size()));

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

int main()
{
    vector<int> vec_a = {5, 10, 15, 20, 30};
    vector<int> vec_b = {6, 11, 15, 18, 19, 35, 50};

    vector<int> result;

    merge(result, vec_a, vec_b);

    for (int elem : result)
    {
        cout << elem << " ";
    }
    cout << endl;
}
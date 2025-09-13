#include <iostream>
#include <vector>

void merge(std::vector<int> &vec, int left, int mid, int right)
{
    /**
     * *Creating Two Subarray
     */
    std::vector<int> lvec(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rvec(vec.begin() + mid + 1, vec.begin() + right + 1);

    /**
     * * Adding Sentinel Value
     */
    lvec.push_back(INT_MAX);
    rvec.push_back(INT_MAX);

    int i{0}, j{0}, k{left};

    /**
     * * Sorting and Storing Value to the given Array
     */
    while (k <= right)
    {
        if (lvec[i] <= rvec[j])
        {
            vec[k++] = lvec[i++];
        }
        else
        {
            vec[k++] = rvec[j++];
        }
    }
}

void merge_sort(std::vector<int> &vec, int start, int end)
{
    //* Base Case Scenario
    if (start >= end)
        return;

    int mid = start + (end - start) / 2; //* Calculating mid and this prevents the integer overflow issue

    merge_sort(vec, start, mid); //* Sorting the left half

    merge_sort(vec, mid + 1, end); //* Sorting the right half

    merge(vec, start, mid, end); //* merging the two halves
}

void print_vector(std::vector<int> &vec)
{
    std::cout << "[";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << ((it == vec.end() - 1) ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> vec{47, 52, 6, 9, 79, 13};
    merge_sort(vec, 0, vec.size() - 1);
    print_vector(vec);

    return 0;
}
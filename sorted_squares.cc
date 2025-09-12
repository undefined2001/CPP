#include <vector>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

vector<int> sorted_squares(vector<int> &nums)
{
    vector<int> res(nums.size(), 0);
    int left{0};
    int right(nums.size() - 1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            res[i] = nums[left] * nums[left];
            left++;
        }
        else
        {
            res[i] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

int main()
{
    vector<int> vec = {-4, -2, 0, 1, 2, 3};
    vector<int> res = sorted_squares(vec);
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
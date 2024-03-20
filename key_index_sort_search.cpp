#include <bits/stdc++.h>
// #include <vector>
using namespace std;

class KeyIndex
{
public:
    int max;
    vector<int> myarr;
    KeyIndex(int arr[], int length)
    {
        max = INT_MIN;
        for (int i = 0; i < length; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        myarr.resize(max * 2 + 1);

        for (int i = 0; i < length; i++)
        {
            myarr[arr[i] + max]++;
        }
    }
    bool KeyIndexSearch(int val);
    vector<int> KeyIndexSorting();
};

bool KeyIndex::KeyIndexSearch(int val)
{
    return (myarr[val + max] != 0) ? true : false;
}

vector<int> KeyIndex::KeyIndexSorting()
{
    int count = 0;
    
    for (int i = 0; i < myarr.size(); i++)
    {
        if (myarr[i] != 0)
        {
            count++;
        }
    }

    vector<int> newarr(count);
    int i = 0;

    for (int j = 0; j < myarr.size(); j++)
    {
        if (myarr[j] > 0)
        {
            newarr[i] = j - max;
            i++;
        }
    }
    return newarr;
}

int main()
{
    int arr[] = {-5, -7, -8, -6, 1, 3, 5, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    KeyIndex a(arr, len);

    //Searching a value using KeyIndexSearch
    cout << a.KeyIndexSearch(4)<< endl;


    //Storing the sorted Vector which returns from KeyIndexSort Function
    vector<int> b = a.KeyIndexSorting();
    for (int i : b)
    {
        cout << i << " ";
    }
    cout<<endl;

    return 0;
}
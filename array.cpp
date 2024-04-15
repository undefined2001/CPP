#include <bits/stdc++.h>
using namespace std;
int main()
{

    array<int, 4> arr = {1, 2, 3, 5};
    cout << arr.at(2) << endl; // Acess elements with index
    cout << arr.front() << endl; // return first element
    cout << arr.back() << endl; // return last element
    cout << arr.size() << endl; // return size pr number of element

    return 0;
}
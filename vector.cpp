#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    vector<int> v(5, 3); // A vector with defined size and initial elements
    vector<int> a(v);    // Coping a vector into another

    vec.push_back(10); // Add element at the end
    vec.push_back(5);
    vec.push_back(30);
    vec.push_back(50);
    vec.push_back(90);
    vec.pop_back(); // Remove the last element

    cout << "Element of Index 2 " << vec.at(2) << endl;       // Random access element with index
    cout << "Front/ First element " << vec.front() << endl;   // Return first element
    cout << "Back/ Last element " << vec.back() << endl;      // Return last element
    cout << "Capacity " << vec.capacity() << endl;            // Return the capacity
    cout << "Number of element/ Size " << vec.size() << endl; // Return the size

    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}
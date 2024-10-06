#include <bits/stdc++.h>
#include <map>

using namespace std;
int main()
{
    // Declaring MAP
    // map<key data type, value data type>
    map<int, string> m;
    m[0] = "Asraful";
    m[5] = "Islam";
    m[10] = "Taj";
    m[15] = "Arifatu";

    // Inserting Value in MAP
    m.insert({20, "Jannat"});

    // Printing Map data
    cout << "Before Erase." << endl;
    for (auto i : m)
    {
        cout << i.first << "-->" << i.second << endl;
    }
    m.erase(5);
    cout << "After Erase." << endl;
    for (auto i : m)
    {
        cout << i.first << "-->" << i.second << endl;
    }

    // Checking if a key exists or Not
    cout << "Is Exists-->" << m.count(20) << endl;

    return 0;
}

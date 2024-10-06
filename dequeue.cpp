#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main()
{
    deque<int> a;
    a.push_front(10); // adding element at the start
    a.push_front(20);
    a.push_front(30);
    a.push_front(40);
    a.push_front(50);
    a.push_front(60);
    // a.pop_front(); // removing element from the beginning
    // a.pop_back(); // removing the last element

    cout << "Max_Size -> " << a.max_size() << endl; // Showing the max size of the dequeue
    cout << "Size -> " << a.size() << endl;         // Showing the size/ Number of item of the dequeue

    cout << "Before Erase: ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    a.erase(a.begin(), a.begin() + 4); // Erase item form e certain range to a certain range
    // begin and end provides the memory address of first and last element

    cout << "After Erase: ";

    for (int i : a)
    {
        cout << i << " ";
    }
}
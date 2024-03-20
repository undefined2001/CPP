#include <bits/stdc++.h>
using namespace std;

class MyInt
{
public:
    int *data;
    MyInt(int *p)
    {
        data = p;
    }
    ~MyInt()
    {
        delete data;
    }

    int &operator*()
    {
        return *data;
    }
};

int main()
{

    return 0;
}
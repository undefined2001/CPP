#include <iostream>
using namespace std;
class Array
{
private:
    int maxSize;
    int usedSize;
    int *pointer;

public:
    Array(Array *a, int max, int used)
    {
        (*a).maxSize = max;
        (*a).usedSize = used;
        (*a).pointer = new int[100];
    }
    void insert(int index, int value)
    {
        if (index <= usedSize)
        {
            for (int i = maxSize - 1; i >= index; i--)
            {
                pointer[i + 1] = pointer[i];
            }
        }
    }
    void setValue()
    {
        for (int i = 0; i < usedSize; i++)
        {
            cout << "Enter Item " << i + 1 << " -->";
            cin >> pointer[i];
        }
    }
    void display()
    {
        cout << "Itemss Are: " << endl;
        for (int i = 0; i < usedSize; i++)
        {
            cout << pointer[i] << endl;
        }
    }
};
int main()
{
    Array info = Array(&info, 10, 30);
}
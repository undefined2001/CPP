#include <iostream>
using namespace std;
class ADTArray
{
private:
    int maxSize;
    int usedSize;
    int *pointer;

public:
    ADTArray(ADTArray *a, int max, int used)
    {
        (*a).maxSize = max;
        (*a).usedSize = used;
        (*a).pointer = new int[maxSize];
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

    ADTArray info = ADTArray(&info, 20, 5);
    info.setValue();
    info.display();

    return 0;
}
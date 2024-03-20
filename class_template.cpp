#include <iostream>
using namespace std;

template <typename T>
class Weight
{
private:
    T kg;

public:
    void setData(T x)
    {
        kg = x;
    }
    T getData()
    {
        return kg;
    }
};

int main(){
    Weight <float>one;
    one.setData(5.5f);
    cout<<one.getData()<<endl;

    return 0;

}
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class CircularArray
{
public:
    int start;
    int size;
    int length;
    vector<int> cir_arr;
    CircularArray(int lin_array[], int st, int sz, int len)
    {
        if (st < 0)
        {
            cout << "Size can not be less than Zero" << endl;
        }
        else
        {
            start = st;
            size = sz;
            length = len;
            cir_arr.resize(length);
            int cirIndex = start;
            int linIndex = 0;
            while (linIndex < size)
            {
                cir_arr[cirIndex % length] = lin_array[linIndex];
                cirIndex++;
                linIndex++;
            }
        }
    }

    void printFullLinear();
    void printForward();
    void printBackward();
    void linearize();
};


//Writing function outside of the class by useing (::)Scope resolution Operator
void CircularArray::printFullLinear()
{
    cout<<"Priting Full Linear --> ";
    int index = 0;
    while (index < cir_arr.size())
    {
        // cout << cir_arr[index % cir_arr.size()] << " ";
        cout << cir_arr[index] << " ";
        index++;
    }
    cout<<endl;
}

void CircularArray::printForward(){
    cout<<"Priting Forward --> ";
    int index = start;
    while(index < start+size){
        cout << cir_arr[index % cir_arr.size()] << " ";
        index++;
    }
    cout<<endl;
}

void CircularArray::printBackward(){
    cout<<"Priting Backward --> ";
    int index = (start+size-1) % cir_arr.size();
    // cout<<index<<endl;
    int loopController = 0;
    while(loopController < size){
        if(index < 0){
            index = cir_arr.size()-1;
        }
        cout << cir_arr[index] << " ";
        index--;
        loopController++;
    }
    cout<<endl;
}

void CircularArray::linearize(){
    int index = 0;
    int count = 0;
}
/*
#This Function Was Created For Testing purpose
*/
void printLinear(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}


int main()
{

    int myarr[8] = {5, 10, 30, 20, 50, 60};
    int len = sizeof(myarr) / sizeof(myarr[0]);
    cout<<"Linear Array: ";
    printLinear(myarr, len);
    CircularArray cir_array(myarr, 3, 6, len);
    cout<<"After Making Circular Array:" <<endl;
    cir_array.printFullLinear();
    cir_array.printForward();
    cir_array.printBackward();

    return 0;
}
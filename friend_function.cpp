#include <bits/stdc++.h>
using namespace std;

class Person{
    string name;
    public:
    void setName(string);
    friend void showInfo(Person a);
};

void Person::setName(string n){
    name = n;
}

//This is a friend function of class Person so it can access the private properties
//But the function is not a part of the class
void showInfo(Person a){
    cout<<"Name: "<<a.name<<endl;
}



int main(){

    Person newperson;
    newperson.setName("Taj");
    showInfo(newperson);
    

    return 0;
}
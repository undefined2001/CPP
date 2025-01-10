#include <iostream>
#include <string>

class Person
{
    std::string name;
    int age;

public:
    Person();
    Person(const std::string &n);
    Person(const std::string &n, int a);

    void print_info();
};

Person::Person(const std::string &n, int a) : name{n}, age{a}
{
}

Person::Person(const std::string &n) : Person{n, 0} {}

Person::Person() : Person{"None", 0} {}

void Person::print_info()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}

int main()
{
    Person p{"Asraful", 23};
    p.print_info();

    return 0;
}
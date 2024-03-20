#include <iostream>

class Person
{
public:
    // instance variables
    std::string m_Name;
    int m_Age;
    
    // Constructor
    Person(std::string, int);

    // Destructor
    ~Person();

    // getter method
    std::string getName() { return m_Name; }
    int getAge() { return m_Age; }
};

Person::Person(std::string name, int age) : m_Name(name), m_Age(age){};
Person::~Person() { std::cout << "Destructor Called" << std::endl; }

int main()
{
    Person p("Taj", 20);
    std::cout << p.m_Name << std::endl;

    return 0;
}
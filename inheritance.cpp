#include <iostream>

class Person
{
    std::string m_Name;
    int m_Age;

public:
    Person(std::string, int);
    void showPersonInfo();
    // std::string getName() { return m_Name; }
    // int getAge() { return m_Age; }
};

Person::Person(std::string name, int age) : m_Name(name), m_Age(age){};

void Person::showPersonInfo()
{
    std::cout << "Name: " << m_Name << std::endl;
    std::cout << "Age: " << m_Age << std::endl;
}

class Student : public Person
{
    int m_StudentId;

public:
    Student(std::string, int, int);
    void showStuedentInfo()
    {
        showPersonInfo();
        std::cout << "Student ID: " << m_StudentId << std::endl;
    }
};

Student::Student(std::string name, int age, int id) : Person(name, age), m_StudentId(id){};

int main()
{
    Person p("Asraful", 23);
    Student s("Taj", 20, 21201627);

    p.showPersonInfo();
    std::cout << std::endl;
    s.showStuedentInfo();

    return 0;
}
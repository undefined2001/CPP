#include <iostream>
#include <string>

class Person
{
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int age)
    {
        this->name = n;
        this->age = age;
    }

    virtual void printData() const = 0;
};

class Student : public Person
{
    int id;

public:
    Student(std::string name, int age, int id) : Person(name, age), id(id)
    {
    }

    void printData() const override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "ID: " << id << std::endl;  // Print the student's ID
    }
};

int main()
{
    Student student("Asraful", 22, 21201627);
    student.printData();  // Call printData to display the student's information

    return 0;
}

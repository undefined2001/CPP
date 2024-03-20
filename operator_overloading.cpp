#include <iostream>
#include <string>

class Student
{
    std::string name;
    int age;

public:
    Student()
    {
        this->name = "";
        this->age = 0;
    };
    Student(std::string, int);
    void setName(std::string);
    void setAge(int);
    std::string getName();
    int getAge();
    bool operator<(Student &);
    Student operator+(Student &);
    friend std::istream &operator>>(std::istream &, Student &);
    friend std::ostream &operator<<(std::ostream &, Student &);
};

Student::Student(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void Student::setName(std::string name)
{
    this->name = name;
}

void Student::setAge(int age)
{
    this->age = age;
}

std::string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

bool Student::operator<(Student &s)
{
    if (this->age < s.age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Student Student::operator+(Student &obj)
{
    std::string new_name = this->name +" "+ obj.name;
    int new_age = this->age + obj.age;
    return Student(new_name, new_age);
}

// Making these function friend so that these can access thzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzqe private property of the class
//  This method overloaded >> operator
std::istream &operator>>(std::istream &input, Student &obj)
{
    input >> obj.name >> obj.age;
    return input;
}

// This method overload << operator
std::ostream &operator<<(std::ostream &output, Student &obj)
{
    output << "Name: " << obj.name << ", Age: " << obj.age;
    return output;
}

int main()
{
    Student student1;
    Student student2;
    std::cin >> student1;
    std::cin >> student2;
    Student student3 = student1 + student2;
    std::cout << student3 << std::endl;
    if (student1 < student2)
    {
        std::cout << student1 << " is Younger" << std::endl;
    }
    else
    {
        std::cout << student2 << " is Younger" << std::endl;
    }
    return 0;
}

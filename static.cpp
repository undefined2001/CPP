#include <iostream>

class Student
{
    std::string name;
    int id;
    static int s_Count;

public:
    Student(std::string name, int id)
    {
        this->name = name;
        this->id = id;
        s_Count++;
    }
    std::string getName()
    {
        return this->name;
    }
    int getId()
    {
        return this->id;
    }
    static int s_getCount()
    {
        return s_Count;
    }
};

int Student::s_Count;

int main()
{
    Student s1("Asraful", 120);
    Student s2("Islam", 121);
    Student s3("Taj", 122);
    int count = Student::s_getCount();
    std::cout << count << std::endl;

    return 0;
}
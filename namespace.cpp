#include <iostream>

namespace test
{
    class Student
    {
    public:
        int id;
        std::string name;
        Student(std::string, int);
    };
}
test::Student::Student(std::string n, int id)
{
    name = n;
    this->id = id;
}

// using namespace test;

int main()
{
    test::Student s("Taj", 21201627);

    std::cout << s.id << " " << s.name << std::endl;

    return 0;
}

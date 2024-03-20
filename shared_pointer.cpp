#include <bits/stdc++.h>
#include <memory>

class Student
{
public:
    std::string name;
    int age;
    Student(std::string name, int age) : name(name), age(age) {};
    ~Student() { std::cout << this << " Student Destructor is Called" << std::endl; }
};

/*
A shared pointer is a way to manage dynamically allocated memory in C++. It is a type of smart pointer that keeps track of the number of pointers pointing to a specific object. When the last pointer is deleted or goes out of scope, the object is automatically deleted.
*/

int main()
{
    /*
    We dont have to care about deleting shared_ptr since it auto delete the object when is went out
    of the bond or we can say when our main function compeletely excicuted
    */

    // Declaring a shared ptr of student class with parametere
    std::shared_ptr<Student> s1 = std::make_shared<Student>("Taj", 22);
    std::shared_ptr<Student> s2 = s1;
    std::unique_ptr<Student> s;
    // Making a simple Student class pointer
    Student *s3 = new Student("Arifa", 22);
    std::cout << "Name is: " << s1->name << std::endl;
    std::cout << "Age is: " << s2->age << std::endl;
    std::cout << "Name is: " << s3->name << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    delete (s3);
    return 0;
    /*
    In the output we will see that the shared pointer odject is automatically deleted
    but the Studnet class pointer we need to delete it mannually
    */
}
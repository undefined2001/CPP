#include <iostream>
#include <cstring>

class Box
{
    char *shape;
    int height;
    int width;

public:
    Box(char *shape, int h, int w);
    Box(const Box &other);
    void print_info();
};

Box::Box(char *s, int h, int w) : shape(new char[strlen(s)]), height(h), width(w)
{
    strcpy(this->shape, s);
}

Box::Box(const Box &other) : Box(other.shape, other.height, other.width)
{
    std::cout << "Copy Constructor Called" << std::endl;
}

void Box::print_info()
{
    std::cout << "Shape: " << this->shape << std::endl;
    std::cout << "Height: " << this->height << std::endl;
    std::cout << "Width: " << this->width << std::endl;
}

int main()
{
    Box my_box{(char *)"Square", 10, 10};
    my_box.print_info();
    Box new_box(my_box);
    new_box.print_info();

    return 0;
}
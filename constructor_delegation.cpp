#include <iostream>

class Square
{
    int width;
    int area;
    std::string color;

public:
    Square(int width);
    Square(int width, std::string color);
    void print();
};

Square::Square(int width) : width(width), area(width * width), color("Red"){};

Square::Square(int width, std::string color) : Square(width)
{
    this->color = color;
};

void Square::print()
{
    std::cout << "Width: " << width << std::endl
              << "Area: " << area << std::endl
              << "Color: " << color << std::endl;
}

int main()
{
    Square square(5, "Pink");
    square.print();

    return 0;
}
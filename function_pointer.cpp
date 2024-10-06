#include <iostream>

double add(double a, double b)
{
    return a + b;
}
double sub(double a, double b)
{
    return a - b;
}
double mul(double a, double b)
{
    return a * b;
}
double div(double a, double b)
{
    return a / b;
}

double (*f_array[5])(double, double) = {NULL, &add, &sub, &mul, &div};

int main()
{
    char opt;
    double a, b;
    while (true)
    {
        std::cout << "******Select an Otion From Below*******\n";
        std::cout << "1. Addition.\n";
        std::cout << "2. Subtraction.\n";
        std::cout << "3. Multiplication.\n";
        std::cout << "4. Division.\n";
        std::cin >> opt;
        if (opt == 'Q' || opt == 'q')
        {
            break;
        }
        std::cout << "Enter two Number separated by space: ";
        std::cin >> a >> b;
        std::cout << "Result is: " << f_array[(int)(opt - '0')](a, b) << "\n";
    }
}
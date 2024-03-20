#include <iostream>

int main()
{
    float vin = 6.04f, req = 26.91f;
    float r;
    std::cout << "Enter the Resistance vlaue in (Kohm): ";
    std::cin >> r;
    double res = vin * (r / req);
    std::cout << "Voltage: " << res << std::endl;

    return 0;
}
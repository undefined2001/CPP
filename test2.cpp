#include <iostream>

int mod8(int number) {
    return number & 0b111;
}

int main() {
    int number = 16; // Example number
    int result = mod8(number);
    std::cout << "Result of " << number << " % 8 using bit shifting: " << result << std::endl;
    return 0;
}

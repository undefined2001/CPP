#include <iostream>

int main()
{
	int a = 10;
	int *ptr{nullptr};

	ptr = &a;

	std::cout << *ptr << std::endl;
	

	return 0;
}
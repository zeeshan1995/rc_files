

#include <iostream>

int* tmp()
{
	static  int x = 25;
	std::cout << &x << "\n";
	return &x;
}

int main()
{
	auto x =tmp();
	std::cout << x << "\n";
}

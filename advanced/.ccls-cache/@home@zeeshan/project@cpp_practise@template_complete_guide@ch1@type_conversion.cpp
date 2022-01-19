
#include <iostream>
#include <string>

template <typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

int max(int a, int b)
{
	return b < a ? a : b;
}

template <typename T>
void f(T x = std::string{""}){}

int main()
{
	std::cout << ::max(1,2) << "\n";
	std::cout << ::max(std::string{"apple"}, std::string{"ball"}) << "\n";
	f(23);
	f();
}

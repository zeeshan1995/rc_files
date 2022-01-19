
#include <iostream>

void print(){}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
	std::cout << "[ types: " << sizeof...(Types) << ", args: " << sizeof...(args) << "]\n";
	std::cout << firstArg << "\n";

	print(args...);
}

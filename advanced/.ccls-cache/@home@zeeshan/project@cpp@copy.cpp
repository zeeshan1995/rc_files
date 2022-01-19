

#include <iostream>
#include <typeinfo>

template<typename T>
void copy(T & from, T & to)
{
	std::cout << "here\n";
}

int main()
{
	std::cout << "name\n";
	copy("name","hell");
}

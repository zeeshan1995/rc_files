

#include <iostream>
#include "../../utils/type_name.hpp"

int main()
{
	
	int n = 25;
	int & reff = n;
	int const & const_ref = n;


	auto &&x = n;
	auto &&y = reff;
	auto && z = std::forward<decltype(const_ref)>(const_ref);

	std::cout << type_name<decltype(x)>() << "\n";
	std::cout << type_name<decltype(y)>() << "\n";
	std::cout << type_name<decltype(z)>() << "\n";
	
	int a = 100;
	int & b = a;

	std::cout << "&a => [" << &a << "]\n";
	std::cout << "&b => [" << &b << "]\n";
	b = n;
	std::cout << "&b => [" << &b << "]\n";
	std::cout << type_name<decltype(b)>() << "\n";

	auto c = b;
	std::cout << type_name<decltype(c)>() << " " << a <<"\n";

}

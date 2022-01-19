

#include <iostream>

#define ILIST
#include "../../utils/foo.hpp"


int main()
{
	std::cout << "foo a: \n";
	foo a;

	std::cout << "\nfoo b(): \n";
	foo b();
	std::cout << "\nfoo c{}: \n";
	foo c{};

	std::cout << "\nfoo d = 23 : \n";
	foo d = 23;
	
	std::cout << "\nfoo e = {23} : \n";
	foo e = {23};

	
	std::cout << "\nfoo f = foo{23} : \n";
	foo f = foo{23};


	std::cout << "foo g(a)\n";
	foo g{e};
	std::cout <<"\n\nDestruction started\n";

	int x  ={1.0};
	std::cout << x<< "\n";
}

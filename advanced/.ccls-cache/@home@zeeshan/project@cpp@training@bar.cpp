

#include <bar.hpp>
#include <foo.hpp>
#include <iostream>

void bar()
{
	std::cout << "In bar()\n";
	foo();
}

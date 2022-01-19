

#include <iostream>
#include <string>

inline void by_copy(int a)
{
	a = 100;
}

inline void by_ref(int & a)
{
	a = 100;
	try{
	a = a/0;
	}
	catch(std::exception const &)
	{

	throw std::runtime_error(std::string{" at "} + __FILE__  ":" + __LINE__);
	}
}

int main()
{
	int a = 10;
	by_copy(a);
	std::cout << a << "\n";
	by_ref(a);
	std::cout << a << "\n";
}

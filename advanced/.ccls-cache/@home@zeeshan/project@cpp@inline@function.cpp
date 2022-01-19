

#include <iostream>

inline int sum(int const & a, int const & b)
{
	return a + b;
}

int main()
{
	int a=0,b=25;
	int i=25;
	std::cout << sum(a,b) << "\n";
}

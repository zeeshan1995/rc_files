

#include <iostream>


const int & xx(int const & x)
{
	return x;
}


int main()
{
	int z = 5;
	xx(5) = 6;
}

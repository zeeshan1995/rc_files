#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
int main()
{
	const long double pi = 3995.0081000;//td::acos(-1.L);
	std::cout << "default precision (6): " << pi << '\n'
		<< "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
		<< "max precision:         "
		<< std::setprecision(std::numeric_limits<long double>::digits10 + 1)
		<< pi << '\n';
}



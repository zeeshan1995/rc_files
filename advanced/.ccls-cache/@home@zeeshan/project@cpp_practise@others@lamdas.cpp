

//https://stackoverflow.com/questions/5501959/why-does-c11s-lambda-require-mutable-keyword-for-capture-by-value-by-defau


#include <iostream>

int main()
{
	int n = 20;

	auto add = [n] (int const & a) mutable{ n+=a; return n; };

	std::cout << add(5) << "\n";
	std::cout << n << "\n";
	std::cout << add(10) << "\n";
}

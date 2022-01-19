

#include <iostream>

int main()

{
	int const && num = 24;
	auto x = num;
	const auto y = &num;
	x.a;
	y.b;
}




#include <iostream>
#include <utility>

int main()
{
	int n = 25;
	//int && a = n;
	int && b = std::move(n); // std::moves is a casting operator. It cast lvalue to rvalue 
	auto p = std::move(25);
	std::cout << b << " " << n << "\n";
}

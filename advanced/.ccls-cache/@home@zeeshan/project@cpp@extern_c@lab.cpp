

#include <iostream>
#include <string>

int main()
{
	std::string s = "apple";
	auto x = s.c_str();
	std::cout << (long long)&s << " " << (long long)&x << "\n";
}



#include <iostream>
#include <string>

int main()
{
	std::string a, b, c;
	std::cin >> a;

	std::cin.ignore();
	std::getline(std::cin, b);

	std::cin.ignore();
	std::getline(std::cin, c);

	std::cout << a << " " << b << " " << c << "\n";
	
}

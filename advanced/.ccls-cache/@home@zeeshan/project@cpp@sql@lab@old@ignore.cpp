

#include <iostream>
#include <string>

std::string input()
{
	std::cout << "here\n";
	std::string s;
//	std::cin.ignore(100,'\n');
	std::getline(std::cin, s);
	return s;
}


int main()
{
	for(int i=1;i<5; i++)
	{
		std::cout << input() << "\n";
	}
}

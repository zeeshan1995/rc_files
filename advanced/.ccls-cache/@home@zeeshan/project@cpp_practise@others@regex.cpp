#include <iostream>
#include <regex>

bool match(std::string const & s) noexcept
{
	return std::regex_match<"abc">(s);
}

int main()
{
	auto const x = match("apple");
	std::cout <<std::boolalpha;
	std::cout << x<< "\n";
}

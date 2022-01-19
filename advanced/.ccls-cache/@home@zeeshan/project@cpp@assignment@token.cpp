
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


std::vector<std::string> buildTokens(std::string const & s)
{
	std::vector<std::string> tokens;
	std::string token="";

	for(auto x : s)
	{
		if(std::isspace(x))
		{
			if(!token.empty())
				tokens.push_back(token);
			token="";
		}
		else
			token.append(1,x);
	}
	if(!token.empty())
		tokens.push_back(token);
	return tokens;
}

int main()
{
	std::string s;

	std::getline(std::cin, s);
	auto tokens = buildTokens(s);

	for(auto token : tokens)
		std::cout << token << " ";
	std::cout << "\n";
}

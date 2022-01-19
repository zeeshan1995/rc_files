
/*
 *
 * Reverse this string 1+2*3-20. Note: 20 must be retained as is. 
 * Expected output: 20-3*2+1
 *
 */
 
#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> _getTokens(std::string const & s)
{
	std::string num="";
	std::vector<std::string>tokens;
	for(auto x : s)
	{
		if(x==' ' or x=='*' or x=='+' or x=='-' or x=='/')
		{
			if(!num.empty())
			{
				tokens.push_back(num);
				num="";
			}
			tokens.push_back(std::string(1,x));
		}
		else
			num.append(1,x);
	}
	if(!num.empty())
		tokens.push_back(num);
	return tokens;
}

std::string _buildReverseString(std::vector<std::string> const & tokens)
{
	std::string s="";
	for(int i = tokens.size()-1; i>=0; --i)
		s+=tokens[i];
	return s;
}

std::string reverseExpression(std::string const & s)
{
	return _buildReverseString(_getTokens(s));
}

int main()
{
	std::string expression;
	std::getline(std::cin, expression);

	std::cout << reverseExpression(expression) << "\n";
}

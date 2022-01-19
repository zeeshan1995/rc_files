

#include <iostream>
#include <string>
#include <sstream>

std::string change(std::string s)
{
	std::string r;

	for(auto x: s)
		r+=std::tolower(x);
	r[0] = std::toupper(r[0]);
	return r;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	std::cin >> t;
	std::cin.ignore();
	while(t--)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);
		
		std::string ans,s;
		iss >> ans >> s;
		while(iss)
		{
			std::cout << change(ans)[0] << ". ";
			ans = s;
			iss >> s;
		}
		if(s=="\0")
			s = ans;
		std::cout << change(s) << "\n";
	}
}

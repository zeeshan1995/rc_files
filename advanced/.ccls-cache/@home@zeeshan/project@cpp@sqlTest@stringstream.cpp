

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

int main()
{
	std::string s = "name:zeeshan class:12 roll:15 subject:Physics";

	std::stringstream ss(s);

	std::string colnames, values;

	while(!ss.eof())
	{
		std::string s;
		ss >> s;
		std::cout << s << "\n";
		auto it = std::find(s.begin(), s.end(),':');
		if(!colnames.empty())
		{
			colnames+=",";
			values+=",";
		}
		colnames+=s.substr(0, it- s.begin());
		values+=s.substr(it- s.begin()+1,s.size());
	}
	std::cout << colnames << " "<< values << "\n";
#if 0
	while(!ss.eof())
	{
		ss >> s;
		std::cout << s << " ";
		auto it = std::find(s.begin(), s.end(), ':');
		std::cout << it-s.begin() << " ";
		std::cout << s.substr(it - s.begin(),s.size()) << "\n";
	}
#endif
}

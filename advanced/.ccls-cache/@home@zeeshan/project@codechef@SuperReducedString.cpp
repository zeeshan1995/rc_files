

#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	std::string f="";

	for(int i=0; i<int(s.size()); i++)
	{
		if(!f.empty() and s[i]==f.back())
			f.erase(f.size()-1);
		else
			f.push_back(s[i]);
	}
	if(f.empty())
		std::cout << "Empty String\n";
	else
		std::cout << f << "\n";
}

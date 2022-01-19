

#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	int i=0;
	while(i+1!=int(s.size()) and s[i] <= s[i+1])
		i++;
	while(i>=0 and s[i]==s[i-1])
		--i;
	if(i!=int(s.size())-1)
		s[i]--;
	i++;
	while(i<int(s.size()))
		s[i++]='9';
	while(s[0]=='0')
		s.erase(0,1);
	if(s.empty())
		s="0";
	std::cout << s << "\n";
}

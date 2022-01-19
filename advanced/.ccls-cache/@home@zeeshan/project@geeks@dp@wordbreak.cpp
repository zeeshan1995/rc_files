

#include <iostream>
#include <string>
#include <unordered_map>
std::unordered_map<std::string,int>words;

bool solve(std::string s,int i)
{
	if(i>=s.size())
		return true;
	std::string tmp = "";

	for(i;i<s.size();i++)
	{
		tmp+=s[i];
		if(words.find(tmp) != words.end() and solve(s,i+1))
			return true;
	}
	return false;
}

int main()
{
	words["i"]++;
	words["like"]++;
	words["sam"]++;
	words["sung"]++;
	words["samsung"]++;
	words["mobile"]++;
	words["ice"]++;
	words["cream"]++;
	words["icecream"]++;
	words["man"]++;
	words["go"]++;
	words["mango"]++;

	std::cout << solve("ilikesamsung",0);
}

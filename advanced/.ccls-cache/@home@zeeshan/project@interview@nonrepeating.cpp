


#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string s = "GEEKSFORGEEKS";

	std::vector<int>pos(26,-1);
	int max = 1,p=0,ansp=0;;
	pos[s[0]-'A']=0;

	for(int i=1; i<s.size(); i++)
	{
		if(pos[s[i]-'A'] >= p)
		{
			if(max < i-p)
				max = i-p,ansp=p;
			p=i;
		}
		pos[s[i]-'A'] = i;
	}
	std::cout << max << "\n";
	std::cout << s.substr(ansp,max) << "\n";
}



#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	int a;
	char c;
	std::cin >> c >> a;
	std::vector<std::pair<char,int>>ans;
	ans.push_back({c,a});
	int r;
	for(int i=1;i<n;i++)
	{
		int b;
		std::cin >> c >> b;

		if(c=='&')
			r = a & b;
		else if (c=='|')
			r = a | b;
		else
			r = a ^ b;
		if(r!=a)
		{
			a=r;
			ans.push_back({c,b});
		}
	}
	if(r==0)
	{	std::cout << 0 << "\n";
		return 0;
	}
	std::cout << ans.size() << "\n";
	for(auto x : ans)
		std::cout << x.first << " " << x.second << "\n";
}

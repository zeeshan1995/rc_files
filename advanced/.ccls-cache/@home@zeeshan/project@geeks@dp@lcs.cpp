

#include <iostream>
#include <vector>
#include <string>

std::string s1,s2;

std::vector<int>ans;
int solve(int i,int j)
{
	if(i<0 or j<0)
		return 0;
	if(s1[i] == s2[j])
	{
		ans[i]=1+solve(i-1,j-1);
		return ans[i];
	}
	else
	{
		return std::max(solve(i-1,j), solve(i,j-1));
		return ans[i];
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	std::cin >> s1  >> s2;
	if(s1.size() < s2.size())
		std::swap(s1,s2);
	ans.resize(s1.size(),-1);
	int z;
	z=solve(s1.size()-1,s2.size()-1);

	std::cout <<z<< "\n";
	std::cout << s1<<"\n";
	for(auto x : ans)
		std::cout << x;
	std::cout <<"\n";

	for(int i=s1.size()-1;i>=0; --i)
	{
		if(ans[i]==z)
		{
			std::cout << s1[i];
			z--;
		}
	}
}

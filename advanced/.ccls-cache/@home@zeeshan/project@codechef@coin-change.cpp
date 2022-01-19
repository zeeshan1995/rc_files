

#include <iostream>
#include <vector>

std::vector<int>coins;//(m);

int solve(int n)
{
	if(n==0)
		return 1;
	else if(n<0)
		return 0;
	int y = 0;
	for(auto x : coins)
		y+=solve(n-x);
	return y;
}
int main()
{
	int n,m;
	std::cin >> n >>m;

	coins.resize(m);
	for(auto & x : coins)
		std::cin >> x;

	std::vector<int>ans(n+5,0);
	ans[0]=1;
	for(int i=0; i<=n; i++)
	{
		if(!ans[i])
			continue;
		for(int j=0;j<m; j++)
		{
			if(i+coins[j] <=n)
				ans[i+coins[j]]+=ans[i];
		}
	}
	std::cout <<ans[n] << "\n";
}

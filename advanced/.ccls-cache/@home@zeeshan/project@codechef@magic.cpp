
#include <iostream>
#include <vector>


int n;
std::vector<std::vector<int>>cost;

int solve(int i,int pre)
{
	int tmp=-1;

	for(int j=0;j<cost[i].size();j++)
	{
		
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		std::cin >> n;

		for(int i=0;i<n;i++)
		{
			int m;
			std::cin >> m;
			std::vector<int>tmp(m);
			for(int j=0;j<m;j++)
				std::cin >> tmp[i];
			cost.push_back(tmp);
				
		}

		std::cout << solve(0,0) << "\n";
	}
}

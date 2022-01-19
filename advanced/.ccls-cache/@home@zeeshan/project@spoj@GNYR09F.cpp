

#include <iostream>
#include <vector>
#include <algorithm>

int n,k;

std::vector<std::vector<std::vector<int>>>dp;//(100,std::vector<std::vector<int>(100,std::vector<int>(2,0)));

int solve(int n, int k, int l)
{
		if(n==1)
		{
					if(k==0)
					{
							if(l)
								return 1;
							else
								return 2;
					}
					else if(k==1)
					{
							if(l)
									return 1;
							else
									return 0;
					}
					else
							return 0;
		}
		if(dp[n][k][l]!=-1)
				return dp[n][k][l];
		if(k>0)
		{
				if(l)
						dp[n][k][l] = solve(n-1,k-1,1) + solve(n-1,k,0);
				else
						dp[n][k][l] = solve(n-1,k,1) + solve(n-1,k,0);
		}
		else
		{
				if(l)
						dp[n][k][l]=solve(n-1,k,0);
				else
						dp[n][k][l] = solve(n-1,k,1) + solve(n-1,k,0);
		}
		return dp[n][k][l];
}
int main()
{
		std::ios_base::sync_with_stdio(false);

//		freopen("input.txt", "r" ,stdin);
		int t;
		std::cin >> t;

		for(int i=0; i<t; i++)
		{
				int x;
		std::cin >> x >> n >> k;

		std::cout << x <<" ";
		if(n==1)
		{
				if(k==0)
						std::cout << 2 << "\n";
				else
						std::cout << 0 << "\n";
				continue;
		}
		dp.clear();
		dp.resize(n+5,(std::vector<std::vector<int>>(k+5,std::vector<int>(2,-1))));

		std::cout << solve(n-1,k,0) + solve(n-1,k,1) << "\n";;
/*
		for(auto x : dp)
		{
				for(auto y : x)
				{
						for(auto z : y)
								std::cout << z <<" ";
						std::cout << "\n";
				}
		}
		*/
		}
}

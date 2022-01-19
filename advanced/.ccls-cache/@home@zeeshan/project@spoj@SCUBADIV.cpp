

//http://www.spoj.com/problems/SCUBADIV/

#include <iostream>
#include <vector>
#include <algorithm>

struct data
{
		int ox;
		int ni;
		int w;
};


template<typename T>
using d2 = std::vector<std::vector<T>>;
template<typename T>
using d3 = std::vector<d2<T>>;

std::vector<data>cyl;

d3<int> dp;//(n+5,d2<int>(ox+5,std::vector<int>(ni+5,-1)));

int solve(int i, int ox, int ni)
{
		if(ox==0 and ni==0)
				return 0;
		if(i<0)
				return 1e9;
		if(dp[i][ox][ni] != -1)
				return dp[i][ox][ni];
		else
				dp[i][ox][ni] = std::min(solve(i-1,ox,ni), 
												solve(i-1, std::max(ox-cyl[i].ox, 0), std::max(ni-cyl[i].ni,0)) + cyl[i].w);
		return dp[i][ox][ni];
}
int main()
{
		std::ios_base::sync_with_stdio(false);

		int t;
		std::cin >> t;

		while(t--)
		{
				int ox,ni,n;
				std::cin >> ox >> ni >> n;

				cyl.resize(0);

				for(int i=0; i<n; i++)
				{
						int o,n,w;
						std::cin >> o >> n >> w;
						cyl.push_back({o,n,w});
				}

				dp.resize(n+5,(d2<int>(ox+5,std::vector<int>(ni+5,-1))));
				
				std::cout << solve(n-1, ox, ni) << "\n";
		}
}

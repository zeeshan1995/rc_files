

#include <iostream>
#include <vector>
#include <map>
template<typename T>
using matrix = std::vector<std::vector<T>>;

std::vector<bool>visited;
std::vector<int>dp;
int solve(int u, matrix<int> const & mat)
{
	visited[u] = true;
	if(dp[u]!=-1)
			return dp[u];

	int include=1;
	for(auto x : mat[u])
			include+=solve(x,mat);

	int exclude = mat[u].size();
	for(auto x : mat[u])
	{
			for(auto y : mat[x])
					exclude+=solve(y,mat);
	}
	return dp[u] = std::min(include, exclude);
}

int main()
{
		std::ios_base::sync_with_stdio(false);
/*
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
#endif
*/
		int n;
		std::cin >> n;

		std::vector<std::vector<int>>mat(n);
		for(int i=0; i<n-1; i++)
		{
				int u,v;
				std::cin >> u >> v;

				mat[std::min(--u,--v)].push_back(std::max(u,v));
		//		mat[v].push_back(u);
		}
		visited.resize(n,false);
		dp.resize(n,-1);
/*
		for(auto x : mat)
		{
				for(auto y : x)
						std::cout << y << " ";
				std::cout <<"\n";
		}
		std::cout << "here\n";
		*/
		std::cout << solve(0,mat) << "\n";
}

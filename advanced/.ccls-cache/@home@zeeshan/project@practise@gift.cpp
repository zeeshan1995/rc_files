

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>count;
bool found;
void dfs(int i, int j,std::vector<std::vector<int>> const & g, std::vector<bool> & v)
{
	if(i==j)
	{
		found = true;
		return;
	}

	v[i] = true;
	for(auto const & x : g[i])
	{
		if(!v[x])
			dfs(x,j,g,v);
		if(found)
		{
			++count[x];
			return;
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);

	int n,m;
	std::cin >> n >> m;

	std::vector<std::vector<int>>g(n);

	for(int i=0; i<n-1; i++)
	{
		int u,v;
		std::cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	count.resize(n,0);
	for(int i=0; i<m; i++)
	{
		int a,b;
		std::cin >> a >> b;
		--a;--b;
		std::vector<bool>v(n,false);
		found = false;
		dfs(a,b,g,v);
		++count[a];
	}
	int ans = 0;
	for(auto const & x : count)
		ans = std::max(ans,x);
	std::cout << ans << "\n";
}


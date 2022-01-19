

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>>g;
int t;

void dfs(int u,std::vector<bool> & visited)
{
	t++;
	visited[u] = true;
	for(auto x : g[u])
	{
		if(!visited[x])
			dfs(x,visited);
	}
}
int main()
{
	int t;
	std::cin >> t;

	while(t--)
	{
		int n,m,l,r;
		std::cin >> n >> m >> l>>r;

		g= std::vector<std::vector<int>>(n);

		for(int i=0; i<m; i++)
		{
			int  u,v ;
			std::cin >> u >> v;
			g[--u].push_back(--v);
			g[v].push_back(u);
		}
		std::vector<bool>visited(n,false);

			long long ans= 0;
			for(int i=0; i<n; i++)
			{
				if(visited[i])
					continue;
				t=0;
				dfs(i,visited);
				ans+=l;
				if(l>r)
					ans+=r*(t-1);
				else
					ans+=l*(r-1);
			}
			std::cout << ans << "\n";
	}
}

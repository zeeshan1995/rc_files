


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

std::vector<int>par,l,p;
int sqrth,f;
std::vector<std::vector<int>>child;

void dfs(int i)
{
	if(l[i]<sqrth)
		p[i] = f;
	else
	{
		if(!(l[i]%sqrth))
			p[i] = par[i];
		else
			p[i] = p[par[i]];
	}
	for(auto x: child[i])
		dfs(x);
}

int lca(int a, int b)
{
	while(p[a]!=p[b])
	{
		if(l[a] > l[b])
			a = p[a];
		else
			b = p[b];
	}

	while(a!=b)
	{
		if(l[a] > l[b])
			a = par[a];
		else
			b = par[b];
	}
	return a;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
#endif

	int t;
	std::cin >> t;

	for(int z = 1; z<=t; z++)
	{
		int n;
		std::cin >> n;
		par.resize(n+1);child.resize(n+1);
		int maxl;
		std::vector<bool>root(n+1,true);
		for(int i=1; i<=n; i++)
		{
			int x;
			std::cin >> x;

			for(int j=0; j<x; j++)
			{
				int a;
				std::cin >> a;
				root[a]=false;
				par[a] = i;
				child[i].push_back(a);
			}
		}
		for(int i=1;i<=n; i++)
		{
			if(root[i])
			{
				f= i;
				break;
			}
		}
		l.resize(n+1);
		l[f] = 0;
		std::queue<int>tmp;
		tmp.push(f);
		while(!tmp.empty())
		{
			int x = tmp.front();
			tmp.pop();
			for(auto y : child[x])
			{
				tmp.push(y);
				l[y] = l[x]+1;
				maxl = l[y];
			}
		}

		sqrth = sqrt(maxl);
		p.resize(n+1);
		dfs(f);

		int q;
		std::cin >>q;

		std::cout << "Case "<<z <<":\n";
		for(int i=0; i<q; i++)
		{
			int a,b;
			std::cin >> a >> b;
			std::cout << lca(a, b) << "\n";
		}
	}
}

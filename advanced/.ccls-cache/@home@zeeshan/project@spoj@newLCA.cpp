


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

std::vector<int>par,l,p;
int sqrth,f,n;
std::vector<std::vector<int>>child;

/*
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
*/

int lca(int a, int b)
{
	std::vector<bool>visited(n+1,false);

	while(par[a]!=a)
	{
		a = par[a];
		visited[a] = true;
	}
	visited[a] = true;

	while(!visited[b])
		b = par[b];
	return b;

}
int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int z = 1; z<=t; z++)
	{
		std::cin >> n;
		par.resize(n+1);//child.resize(n+1);
//		int maxl;
//		f=0;
		for(int i=1; i<=n; i++)
		{
			int x;
			std::cin >> x;

			for(int j=0; j<x; j++)
			{
//				if(!f)
//					f=i;
				int a;
				std::cin >> a;
				par[a] = i;
//				child[i].push_back(a);
			}
		}

		/*
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
*/
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

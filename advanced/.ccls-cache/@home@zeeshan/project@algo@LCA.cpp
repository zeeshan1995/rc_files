

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
std::vector<int>t,l,p;
int sqrth;
std::vector<std::vector<int>>child;
void dfs(int i)
{
	if(l[i] < sqrth)
		p[i]=1;
	else
	{
		if(!(l[i]%sqrth))
			p[i] = t[i];
		else
			p[i] = p[t[i]];
	}
	for(auto x : child[i])
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
			a=t[a];
		else
			b = t[b];
	}

	return a;
}
int main()
{

	freopen("input.txt", "r", stdin);
	int n;
	std::cin >> n;

	t.resize(n+1);
	child.resize(n+1);//std::vector<int>>child(n+1);
	t[1] = 1;

	for(int i=1; i<n; i++)
	{
		int a,b;
		std::cin >> a >> b;
		t[a] = b;
		child[b].push_back(a);
	}
	l.resize(n+1);

	l[1] = 0;
	std::queue<int>tmp;
	tmp.push(1);
	int maxl=0;
	while(!tmp.empty())
	{
		int i = tmp.front();
		tmp.pop();
		for(auto x: child[i])
		{
			l[x] = l[i]+1;
			if(l[x] > maxl)
				maxl = l[x];
			tmp.push(x);
		}
	}

	sqrth = std::sqrt(maxl);

	p.resize(n+1);
	dfs(1);
	for(int i=1; i<=n; i++)
		std::cout << i << " " << p[i] <<"\n";

	int q;
	std::cin >> q;

	for(int i=0; i<q; i++)
	{
		int a,b;
		std::cin >> a >> b;
		std::cout << lca(a,b) << "\n";
	}
}

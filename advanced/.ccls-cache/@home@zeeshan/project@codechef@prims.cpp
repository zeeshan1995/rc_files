

#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int,int>

struct node
{
	int v,w;
};

struct compare
{
	bool operator()(const std::pair<int, int> & a, const std::pair<int, int> & b)
	{
		return a.second > b.second;
	}
};
int main()
{
	int n,m;
	std::cin >> n >> m;

	std::vector<std::vector<node>>g(n);

	for(int i=0; i<m; i++)
	{
		int a,b,w;
		std::cin >> a >>b >> w;
		g[--a].push_back({--b,w});
		g[b].push_back({a,w});
	}

	int s;
	std::cin>>s;
	--s;
	std::vector<bool>tree(n,false);
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,compare>pq;

	pq.push({s,0});
	int ans=0,t=0;
	while(t<n)
	{
		int u = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if(tree[u])
			continue;
		ans+=x;
		t++;
		for(int i=0; i<g[u].size(); i++)
		{
			int v = g[u][i].v,w =g[u][i].w;
			//			std::cout << v << " " << w << "\n";
			if(!tree[v])//len[u]+w < len[v])
				pq.push({v,w});
		}
		tree[u]= true;
	}
	std::cout << ans<< "\n";
}

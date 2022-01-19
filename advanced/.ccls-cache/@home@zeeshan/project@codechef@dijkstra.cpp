
#include <iostream>
#include <vector>
#include <queue>


struct node
{
	int v,w;
};

struct compare
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
int main()
{
	int t;
	std::cin >> t;

	while(t--)
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

		std::vector<int>len(n,1e9);
		len[--s]=0;
		std::vector<bool>tree(n,false);

//		std::priority_queue<int>xx;

		std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,compare>pq;

		std::priority_queue<int,std::vector<int>,compare)

		pq.push({s,0});
		while(!pq.empty())
		{
			int u = pq.top().first;
			pq.pop();
			if(tree[u])
				continue;
			for(int i=0; i<g[u].size(); i++)
			{
				int v = g[u][i].v,w =g[u][i].w;
	//			std::cout << v << " " << w << "\n";
				if(!tree[v] and len[u]+w < len[v])
				{
					len[v] = len[u]+w;
					pq.push({v,len[v]});
				}
			}
				tree[u]= true;
		}
		for(int i=0;i<n; i++)
		{
			if(i==s)
				continue;
			if(len[i]==int(1e9))
				len[i]=-1;
			std::cout << len[i] << " ";
		}
		std::cout << "\n";
	}
}

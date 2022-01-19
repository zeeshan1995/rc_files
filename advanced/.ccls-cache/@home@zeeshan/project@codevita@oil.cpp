#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int n,m;
std::vector<std::vector<int> >grid;

int ni[] = {0,0,-1,1}, nj[] = {-1,1,0,0};

int ans = 0;
void dfs(int u, int v, int l,std::vector<std::vector<bool> >visited)
{
	visited[u][v] = true;
	std::vector<std::pair<int,int> >h;
	for(int i=0; i<4; i++)
	{
		int x = u + ni[i],y = v+nj[i];
		if(x>=0 and x< n and y>=0 and y< m and grid[x][y] < grid[u][v] and !visited[x][y])
		{
			std::pair<int,int>a(grid[x][y],i);
			h.push_back(a);
		}
	}
	std::sort(h.begin(), h.end());
	int pre;
	if(!h.empty())
		pre = h.back().first;

	bool next = false;
	for(int i = h.size() - 1; i>=0; --i)
	{
		if(pre == h[i].first)
		{
			next = true;
			int x = u+ni[h[i].second], y=v+nj[h[i].second];
			dfs(x,y,l+1,visited);
			pre = h[i].first;
		}
	}
	if(!next)
	{
		if(l > ans)
			ans = l;
	}
}
int main()
{

	std::string s;
	std::cin >> s;

	std::istringstream ss(s);
	std::string token;

	std::getline(ss,token,',');
	n = atoi(token.c_str());
	std::getline(ss,token,',');
	m = atoi(token.c_str());

	grid.resize(n);
	
	for(int i=0; i<n; i++)
	{
		std::cin >> s;
		std::istringstream ss(s);
		while(std::getline(ss,token,','))
			grid[i].push_back(atoi(token.c_str()));
	}
	int u,v;
	std::cin >> s;
	std::istringstream ss1(s);

	std::getline(ss1,token,',');
	u = atoi(token.c_str());
	std::getline(ss1,token,',');
	v = atoi(token.c_str());
	int l=1;
	std::vector<std::vector<bool> >visited(n,std::vector<bool>(m,false));
	dfs(u-1,v-1,l,visited);
	std::cout << ans <<"\n";
}

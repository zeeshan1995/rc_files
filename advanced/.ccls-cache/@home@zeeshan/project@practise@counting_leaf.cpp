

#include  <iostream>
#include <vector>
#include <algorithm>

int solve(int i, std::vector<std::vector<int>> const & v, std::vector<bool> & visited)
{
	if(v[i].empty())
		return 1;
	visited[i] = true;
	int c = 0;
	for(auto const & x : v[i])
	{
		if(!visited[x])
			c+=solve(x,v,visited);
	}
	return c;
}
int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>>v(n);
	int root = -1;
	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >> a;
		if(	a == -1)
		{
			root = i;
			continue;
		}
		v[a].push_back(i);
	}
	int d;
	std::cin >> d;

	auto leaf = std::count_if(v.begin(), v.end(), [](std::vector<int> i) { return i.size()==0;});
	std::vector<bool>visited(n,false);
	std::cout << leaf - solve(d, v, visited) << "\n";
}



#include <vector>
#include <unordered_map>
#include <iostream>
int main()
{
	int n;
	std::cin >> n;

	std::unordered_map<int,std::vector<int>>x,y;

	std::vector<std::pair<int,int>>points;

	for(int i=0; i<n; i++)
	{
		int a,b;
		std::cin >> a>>b;
		x[a].push_back(i);
		y[b].push_back(i);
	}
}

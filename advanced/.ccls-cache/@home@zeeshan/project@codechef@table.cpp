

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	int n;
	std::cin >>n;

	std::vector<std::pair<int,int>>length;

	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >> a;
		length.push_back({a,i});
	}
	std::vector<int>cost;
	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >> a;
		cost.push_back(a);
	}
	std::sort(length.begin(), length.end());

	std::vector<int>sum;
	sum.push_back(cost[length.back().second]);
	for(int i=n-2;i>=0;--i)
	{
		if(length[i].first==length[i+1].first)
			sum.back()+=cost[length[i].second];
		else
			sum.push_back(cost[length[i].second]);

	}

	for(auto x : sum)
		std::cout << x << " ";
	std::cout <<"\n";

	std::priority_queue<int>q;
	q.push_back(cost[length[0].second]);

	int ans=1e9,int same=1,tillcost=0,till=0;
	for(int i=1,j=1;i<n; i++)
	{
		if(length[i].first==length[i-1].first)
		{
			q.push_back(cost[length[0].second]);
			same++;
		}
		else
		{
			int tmp = sum[j];
		}
	}
}



#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int p, s;
	std::cin>> p >> s;

	std::vector<std::vector<int>>diff(30);
	for(auto i=0; i<p; i++)
	{
		std::vector<std::pair<int,int>>score;
		std::vector<int>sols(s);

		for(auto i=0; i<s; ++i)
		{
			int a;
			std::cin >> a;
			score.push_back({a,i});
		}
		
		for(auto & x : sols)
			std::cin >> x;
		std::sort(score.begin(), score.end());
		auto count = 0;
		for(auto i=0; i<s-1; ++i)
		{
			if(sols[score[i].second] > sols[score[i+1].second])
				count++;
		}
		diff[count].push_back(i);
	}
	for(auto const & x : diff)
	{
		for(auto const & y : x)
			std::cout << y+1 << "\n";
	}
}

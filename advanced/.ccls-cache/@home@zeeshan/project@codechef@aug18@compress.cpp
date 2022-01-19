

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	std::cin >> t;

	while(t--)
	{
		int n,s;
		std::cin >> n >>s;

		std::vector<std::pair<int, int>>nums;
		for(auto i=0; i<n; i++)
		{
			int a;
			std::cin >> a;
			nums.push_back({a,i+1})
		}

		std::sort(nums.begin(), nums.end(), [](auto const & a, auto const & b)
											{
												return a.first < b.first or (a.first == b.first and a.second < b.second)
											}

	}
}

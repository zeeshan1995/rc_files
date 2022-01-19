

//https://www.codechef.com/MARCH18B/problems/MIXCOLOR


#include <bits/stdc++.h>

const long long MAX = 1e5+1;

int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		int n;
		std::cin >> n;

		std::vector<std::pair<long long, int>> nums;

		{
			std::unordered_map<long long, int> index;

			for(int i=0; i<n; ++i)
			{
				int a;
				std::cin >> a;
				if( index.find(a) != index.end() )
					nums[index[a]].second++;
				else
				{
					index[a] = nums.size();
					nums.push_back({a,1});
				}
			}
		}

		index.begin();
		for(auto x : nums)
			std::cout << x.first << " " << x.second << "\n";
	}
}

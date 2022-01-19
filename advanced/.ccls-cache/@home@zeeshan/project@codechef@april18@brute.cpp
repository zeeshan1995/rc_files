

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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
		int n;
		std::cin >> n;

		std::vector<int>nums(n);
		std::unordered_set<int>ss;
		for(auto & x : nums)
		{
			std::cin >> x;
			ss.insert(2*x);
		}
		
		std::sort(nums.begin(), nums.end());

		long long ans =0;
		for(int i=0; i<nums.size(); ++i)
		{
			for(int j=i+1; j<n; j++)
			{
				if(ss.find(nums[i] + nums[j]) != ss.end())
				{
					std::cout << "["<<i << " " <<j << "] ";
					ans++;
				}
			}
		}
		std::cout << ans << "\n";
	}
}

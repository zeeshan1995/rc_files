

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
		int n;
		std::cin >> n;

		std::vector<int>nums(n);
		for(auto & x : nums)
			std::cin >> x;
		
		std::sort(nums.begin(), nums.end());

//		for(auto & x : nums)
//			std::cout<< x<< " ";
//		std::cout << "\n";
//		for(auto & x : ss)
//			std::cout<< x<< " ";
//		std::cout << "\n";


		long long ans =0;
		for(int i=0; i<nums.size(); ++i)
		{
			if(nums[i]==nums[i+1])
				continue;
			int j=i,k=i+1,num = 2*nums[i];
			while(j>=0 and k < n)
			{
				int sum = nums[j] + nums[k];
				if(sum == num)
				{
					std::cout << "[" <<j << " " << k << "] ";
					ans++;
					if(nums[j-1] == nums[j])
						--j;
					else
						++k;
				}
				else if (sum > num)
					--j;
				else
					++k;
			}
		}
		std::cout << ans << "\n";
	}
}

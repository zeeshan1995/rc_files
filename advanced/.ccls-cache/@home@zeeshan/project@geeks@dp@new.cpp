

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main()
{
	int t;
	std::cin  >> t;

	while(t--)
	{
		int n;
		std::cin >>n;

		std::vector<int>nums(n);

		for(auto & x : nums)
			std::cin >> x;

		std::sort(nums.rbegin(),nums.rend());
int i;
		long long tmp=0,even_pos=LLONG_MIN,odd_pos=LLONG_MIN;
		for(i=0;i<nums.size() and nums[i]>=0; i++)
		{
			tmp+=nums[i];
			if(tmp&1)
				odd_pos = tmp;
			else
				even_pos = tmp;
		}

		long long ans = odd_pos;
		for(;i<nums.size();i++)
		{
			if(nums[i]&1)
			{
				if(odd_pos==LLONG_MIN)
				{
					if(even_pos!=LLONG_MIN)
						even_pos+=nums[i];
					else
						even_pos = nums[i];
					ans = std::max(even_pos,ans);
				}
				break;
			}
		}

		std::cout << ans << "\n";
	}
}

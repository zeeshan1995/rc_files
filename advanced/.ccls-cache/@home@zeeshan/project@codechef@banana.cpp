

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main()
{
	std::ios_base::sync_with_stdio(false);
/*
#ifndef ONLINE_JUDE
	freopen("input.txt", "r", stdin);
#endif
*/
	int t;
	std::cin >> t;

	while(t--)
	{
		int n, h;
		std::cin >> n >> h;
		if(n==1)
		{
			long long a;
			std::cin >> a;
			if(h>=a)
				std::cout <<"1\n";
			else
				std::cout << (a+h-1)/h << "\n";
		}
		else if(h-n > n-1)
		{
			long long sum = -1 * n;
			for(int i=0; i<n; ++i)
			{
				long long a;
				std::cin >> a;
				sum+=a;
			}

			long long ans = std::ceil(static_cast<long double>(sum)/static_cast<long double>(h-n));
			std::cout << ans << "\n";
		}
		else
		{
			std::vector<long long>nums;
			for(int i=0; i<n; ++i)
			{
				long long a;
				std::cin >> a;
				nums.push_back(a);
			}

			std::sort(nums.begin(), nums.end());
			std::cout << nums[n- (h-n) -1] << "\n"; 
		}
	}
}

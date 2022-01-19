

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int>nums(n);

	for(auto & x : nums)
		std::cin >> x;

	std::sort(nums.begin(), nums.end());

	std::vector<long double>avg;

	for(long long i=0,sum=0; i<nums.size(); ++i)
	{
		sum+=nums[i];
		avg.push_back(sum/static_cast<long double>(i+1));
	}

#if 0
	for(auto const & x : avg)
		std::cout << x << "\n";
#endif

	int q;
	std::cin >> q;

	for(int i=0; i<q; ++i)
	{
		int k;
		std::cin >> k;
		int p = std::lower_bound(avg.begin(), avg.end(), k) - avg.begin();
		std::cout << p << "\n";
	}
}

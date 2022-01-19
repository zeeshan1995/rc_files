

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxSubarraySum(std::vector<int> const & nums)
{

	int max = nums[0],till=nums[0];

	for(int i=1; i<nums.size(); i++)
	{
		if(nums[i] + till > nums[i])
			till += nums[i];
		else
			till = nums[i];
		if(till > max)
			max = till;
	}
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	std::cin >> n;

	std::vector<int> nums;
	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >> a;
		nums.push_back(a);
	}

	std::cout << maxSubarraySum(nums) << "\n";
}

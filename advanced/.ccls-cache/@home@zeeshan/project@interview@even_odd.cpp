

#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int  a, int  b)
{
	if(!(a&1))
		return true;
	return false;
}
int main()
{
	int n;
	std::cin >> n;

	std::vector<int> nums(n);

	for(auto & x : nums)
		std::cin >> x;


	std::sort(nums.begin(), nums.end(), compare);
}

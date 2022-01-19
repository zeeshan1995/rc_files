

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n,k;
	std::cin >> n >> k;

	std::vector<int>nums(n);

	for(auto & x : nums)
		std::cin >> x;

	std::vector<long long>stack, queue;
	
	stack.push_back(nums.front());
	queue.push_back(nums.back());

	for(int i=1; i<k; i++)
	{
		stack.push_back(nums[i] + stack.back());
		queue.push_back(nums[n-i-1] + queue.back());
	}

	long long max = stack.back();

	for(int i=0; i<k-1; ++i)
		max = std::max(max, stack[i] + queue[k - 2 - i]); 
	
	std::cout << max << "\n";
}

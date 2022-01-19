

#include <iostream>
#include <vector>
#include <stack>


int main()
{
	std::vector<int>nums = {4,2,3,15,10,8,9,11,10};

	std::stack<int>s;
	std::vector<int>sol(nums.size());

	for(int i=nums.size()-1; i>=0; --i)
	{
		while(!s.empty() and s.top()<= nums[i])
			s.pop();
		sol[i] = s.empty() ? -1 : s.top();
		s.push(nums[i]);
	}

	for(auto x : sol)
		std::cout << x << " ";
}

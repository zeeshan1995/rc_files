

#include <iostream>
#include <stack>
#include <vector>
int main()
{
	std::vector<int>nums = {100,80,60,70,75,85}, sol(nums.size());

	std::stack<int>s;
	s.push(0);
	sol[0]=1;
	for(int i=1; i<nums.size(); i++)
	{
		while(!s.empty() and nums[i]>nums[s.top()])
			s.pop();
		if(s.empty())
			sol[i]=i+1;
		else
			sol[i] = i - s.top();
		s.push(i);
	}
	for(auto x : sol)
		std::cout << x << " ";
}

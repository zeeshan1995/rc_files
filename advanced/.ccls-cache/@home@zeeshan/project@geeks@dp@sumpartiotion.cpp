

//http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/

#include <iostream>
#include <vector>

std::vector<int> nums = {3,1,5,9,12};
int solve(int i,int l,int r)
{
	if(i>=nums.size())
	{
		if(l==r)
			return l;
		else
			return -1;
	}
	return std::max(solve(i+1,l+nums[i],r),solve(i+1,l,r+nums[i]));
}
int main()
{

	std::cout << solve(0,0,0);
}

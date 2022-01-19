

#include <iostream>
#include <vector>
std::vector<int> nums = {1,2,3,4,5,6,7,8};

int solve(int i,int c)
{
	if(i>=nums.size())
		return 0;
	if(c==2)
		return solve(i+1,0);
	else
		return std::max(solve(i+1,c+1)+nums[i],solve(i+1,0));
}
int main()
{

	std::cout <<solve(0,0)<<"\n";
}

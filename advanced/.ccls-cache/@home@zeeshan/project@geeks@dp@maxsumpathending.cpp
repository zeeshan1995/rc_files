//http://www.geeksforgeeks.org/maximum-path-sum-position-jumps-divisibility-condition/
//

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums = {-1,2,3,1,4,6,5};
	std::vector<int>ans(nums.size(),0);
	ans[1]=nums[1];
	for(int i=1;i<nums.size();i++)
	{
		for(int j=2*i;j<nums.size();j+=i)
		{
			if(ans[j]<ans[i]+nums[j])
				ans[j]=ans[i]+nums[j];
		}
	}

	for(auto x : ans)
		std::cout << x << " ";
	std::cout <<"\n";
}

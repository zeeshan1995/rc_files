

#include <iostream>
#include <vector>

int main()
{
	std::vector<int>nums = {1,-1, 3, 2, -7, -5, 11, 6};

	int p=0;
	for(int i=0; i<nums.size(); i++)
	{
		if(nums[i]>0)
		{
			int j=i;
			while(j>p)
			{
				std::swap(nums[j-1], nums[j]);
				--j;
			}
			p++;
		}
	}

	for(auto x : nums)
		std::cout << x << " ";
	std::cout << "\n";
}




#include <iostream>
#include <vector>
int main()
{
	std::vector<int>nums = {10,22,9,33,21,50,41,60};
	std::vector<int>size(nums.size(),1);

	for(int i=0;i<nums.size(); i++)
	{
		for(int j=0;j<i;j++)
		{
			if(nums[j] < nums[i] and size[i] < size[j]+1)
				size[i] = size[j]+1;
		}
		std::cout << nums[i] << " " <<size[i] <<"\n";
	}

	for(auto x : nums)
		std::cout << x << " ";
	std::cout <<"\n";
	for(auto x : size)
		std::cout << x << " ";
	std::cout <<"\n";
}

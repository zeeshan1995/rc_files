
#include <iostream>
#include <vector>

void quickSort(std::vector<int> & nums, int l, int r)
{
	if(l>=r)
		return;
	int k=l;
	for(int i=l;i<r; i++)
	{
		if(nums[i] < nums[r])
			std::swap(nums[i], nums[k++]);
	}
	std::swap(nums[k],nums[r]);
	for(auto x : nums)
		std::cout << x << " ";
	std::cout << "\n";
	quickSort(nums,l,k-1);
	quickSort(nums,k+1,r);
}
int main()
{
	std::vector<int>nums = {2,8,7,1,3,5,6,4};
	quickSort(nums,0,nums.size()-1);
}

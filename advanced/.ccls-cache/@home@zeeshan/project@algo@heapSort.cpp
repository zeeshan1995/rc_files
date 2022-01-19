

#include <iostream>
#include <vector>
#include <algorithm>

#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2;
void heapify(std::vector<int> & nums, int i,int size)
{
	int l = left(i), r = right(i),max;
	if(l<size and nums[l] > nums[i])
		max = l;
	else
		max = i;
	if(r<size and nums[r] > nums[max])
		max = r;
	if(max!=i)
	{
		std::swap(nums[i], nums[max]);
		heapify(nums, max, size);
	}
}
int main()
{
	std::vector<int>nums = {0,4,1,3,2,16,9,10,14,8,7};

	for(int i=nums.size()/2;i>=1; i--)
		heapify(nums,i,nums.size());
	int size = nums.size();
	for(int i=nums.size()-1;i>=2; --i)
	{
		std::swap(nums[1],nums[i]);
		size--;
		heapify(nums, 1, size);
	}

	for(auto x : nums)
		std::cout << x << " ";
	std::cout << "\n";
}

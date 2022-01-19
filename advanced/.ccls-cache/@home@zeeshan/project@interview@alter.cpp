

#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector<int> nums = {1,2,3,4,5,6,7};

	int n = nums.size();
	int i=0,j=n-1,x=nums[n-1];
	while(i!=nums.size())
	{
		int e = n-1-j,pos;
		if(e <= n/2)
			pos=2*e;
		else
			pos=2*j+1;
		std::swap(x,nums[pos]);
		j=pos;
		i++;
		std::cout << i << ": ";
		for(auto x : nums)
			std::cout << x << " ";
		std::cout << "\n";
	}

	for(auto x : nums)
		std::cout << x << "\n";
}

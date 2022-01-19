

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	std::vector< unsigned long long> nums;

	nums.push_back(1);
	 unsigned long long i2=0, i3=0, i5 =0;

	while(nums.size() < n)
	{
		 unsigned long long n2 = nums[i2]*2, n3 = nums[i3]*3, n5 = nums[i5]*5;
		nums.push_back(std::min({n2,n3,n5}));
		if(nums.back()==n2)
			i2++;
		if(nums.back()==n3)
			i3++;
		if(nums.back()==n5)
			i5++;
	}


//	for(auto x : nums)
//		std::cout << x << " ";
	std::cout << "\n";
	std::cout << nums.back()<< "\n";
}

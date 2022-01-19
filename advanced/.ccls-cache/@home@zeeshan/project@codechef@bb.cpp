

#include <iostream>
#include <vector>

int main()
{
	int n,k;
	std::cin >> n>>k;

	std::vector<int>nums(n);

	int min=1e9+5,max=-1e9 - 5;

	for(auto & x : nums)
	{
		std::cin >> x;

		if(x>max)
			max = x;
		if(x<min)
			min = x;
	}

	if(k==1)
		std::cout << min << "\n";
	else if(k==2)
	{
		std::vector<int>mins,mine;

		mins.push_back(nums[0]);
		mine.push_back(nums.back());
		for(int i=1;i<n;i++)
		{
			mins.push_back(std::min(nums[i],mins.back()));
			mine.push_back(std::min(nums[n-1-i],mine.back()));
		}

		int ans = -1e9-5;
		for(int i=0;i<n-1;i++)
		{
			ans = std::max(ans,std::max(mins[i],mine[mine.size()-i-2]));
		}
		std::cout <<ans << "\n";
	}
	else
		std::cout << max << "\n";
}

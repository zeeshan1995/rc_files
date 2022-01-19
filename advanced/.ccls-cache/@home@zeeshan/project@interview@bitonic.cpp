

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> nums= {1,2,3,4,5,6};
	std::reverse(nums.begin(), nums.end());

	int s=0,l=1,ans=0,z=0;
	bool decr=false;
	for(int i=1; i<nums.size(); i++)
	{
		if(!decr)
		{
			l++;
			if(nums[i] < nums[i-1])
				decr = true;
		}
		else
		{
			if(nums[i] <=nums[i-1])
				l++;
			else
			{
				if(l > ans)
					ans=l,z=s;
				s=i-1,l=2,decr = false;
			}
		}
	}
				if(l > ans)
					ans=l,z=s;
	std::cout << z << " " << ans << "\n";
}

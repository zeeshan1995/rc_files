

#include <iostream>
#include <vector>

int main()
{
		std::vector<int>nums={1,2,3,4,5,6};
		int k=2;
		for(int i=0; i<=k; i++)
		{
				int x = nums[i];
				for(int j=i+k;j!=i;)
				{
						nums[j]=x;
						j+=k;
						x=nums[(j+k)%nums.size()];
				}
		}

		for(auto x : nums)
					std::cout << x <<" ";
}

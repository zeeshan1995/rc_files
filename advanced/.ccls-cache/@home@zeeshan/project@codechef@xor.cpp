

#include <iostream>
#include <unordered_map>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::unordered_map<int,int>nums;

	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >>a;
		nums[a]=1;
	}
	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >>a;
		nums[a]=2;
	}

	int count = 0;
	for(std::unordered_map<int,int>::iterator it = nums.begin();it!=nums.end();it++)
	{
		auto y=it;

		for(;y!=nums.end();y++)
		{
			if(it->second!=y->second and nums.count((it->first)xor(y->first)))
					count++;
		}
	}
	if(count&1)
		std::cout << "Koyomi\n";
	else
		std::cout << "Karen\n";
}

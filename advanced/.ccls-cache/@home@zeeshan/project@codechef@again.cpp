

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int n;
	std::cin >> n;

	int d=0,tmp=n;

	while(tmp)
	{
		d++;
		tmp/=10;
	}

	std::vector<int>nums;
	for(int i=std::max(n-d*9,0);i<=n;i++)
	{
		tmp=i,d=0;
		while(tmp)
		{
			d+=tmp%10;
			tmp/=10;
		}

		if(i+d==n)
			nums.push_back(i);
	}

	std::cout << nums.size() << "\n";
	for(auto x : nums)
		std::cout << x << "\n";
}

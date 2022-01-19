

#include <iostream>
#include <vector>

int main()
{
	int n;
	long long k;
	std::cin >> n >>k;


	std::vector<int>power(n);

	int max = -1;
	for(auto & x : power)
	{
		std::cin >> x;
		if(max <x)
			max = x;
	}

	long long t=0;

	if(k>=n)
	{
		std::cout << max << "\n";
		return 0;
	}

	int p = power[0];
	for(int i=1;i<n;i++)
	{
		if(p>power[i])
		{
			t++;
		}
		else
		{
			t=1;
			p=power[i];
		}
		if(t>=k)
		{
			std::cout << p << "\n";
			return 0;
		}
	}
	std::cout << p << "\n";
}

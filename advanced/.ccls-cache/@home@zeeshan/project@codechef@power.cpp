

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

	if(power[0] < power[1])
		std::swap(power[0],power[1]);
	if(k>=n)
	{
		std::cout << max << "\n";
		return 0;
	}

	while(t!=k)
	{
		if(power[0]>power[1])
		{
			t++;
			std::swap(power[0],power[1]);
		}
		else
			t=0;
		power.push_back(power[0]);
		power.erase(power.begin());
	}
	std::cout << power[0] << "\n";
}

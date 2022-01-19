

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

int main()
{

	int n;
	std::cin >> n;

	int tmp = n;
	int x = 1;
	while(tmp)
	{
		x*=10;
		tmp/=10;
	}

	const int MAX = n*x + n + 1;

	std::vector<bool>nums(MAX,true);
	std::vector<int>primes,size;

	int l = sqrt(MAX);
	for(int i=2; i<=l; i++)
	{
		if(!nums[i])
			continue;
		if(i<=n)
		{
			primes.push_back(i);

			tmp = i;
			x = 1;
			while(tmp)
			{
				x*=10;
				tmp/=10;
			}
			size.push_back(x);
		}
		for(int j=2*i;j<MAX; j+=i)
			nums[j] = false;
	}

	for(int i=l+1; i<=n; i++)
	{
		if(nums[i])
			primes.push_back(i);
	}
	std::set<int>zz;
	for(int i=0; i<(int)primes.size(); i++)
	{
		for(int j=0; j<(int)primes.size(); j++)
		{
			if(nums[size[j]*primes[i] + primes[j]])
				zz.insert(size[j]*primes[i] + primes[j]);
		}
	}
	std::cout << zz.size() << "\n";
}


#include <iostream>

const int MOD = 1e9+7;

int main()
{
	int n;
	std::cin >> n;
	
	long long result = 1, base = 2, exponent = n-1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % MOD;
		exponent = exponent >> 1;
		base = (base * base) % MOD;
	}

	std::cout << std::max(0ll,result  - 2) << "\n";
}

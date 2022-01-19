

#include <iostream>
#include <cmath>

constexpr int MOD = 1e9+7;

unsigned long long exp_mod(unsigned long long base, unsigned long long exponent, unsigned long long modulus)
{
    unsigned long long result = 1;
	base = base % modulus;
    while(exponent > 0)
	{
        if (exponent & 1)
           result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
	}
    return result;
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	return b==0 ? a : gcd(b, a%b);
}

int main()
{
	std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	std::cin >>t;
	while(t--)
	{
		unsigned long long a, b, n;
		std::cin >> a >> b >> n;
		unsigned long long m = a>b ? a-b : b-a; 
		if(m !=0 )
		{
			unsigned long long c = (exp_mod(a, n, m) + exp_mod(b, n, m)) % m;
			std::cout << gcd(m,c)%MOD << "\n";
		}
		else
			std::cout << (2 * exp_mod(a, n, MOD)) % MOD << "\n";
	}
}

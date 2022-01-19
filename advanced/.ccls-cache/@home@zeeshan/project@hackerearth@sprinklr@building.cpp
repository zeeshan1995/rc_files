

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;

	const long long MOD = 1e9 + 7;

    while(t--)
    {
        long long n, k;
        std::cin >> n >> k;
		
        auto result = 1LL;
        auto base = k-1;
	    auto exponent = n-1;
        while(exponent > 0)
	    {
            if(exponent % 2 == 1)
               result = (result * base) % MOD;
            exponent = exponent >> 1;
            base = (base * base) % MOD;
        }
        std::cout << (result * k) % MOD << "\n";
    }
}

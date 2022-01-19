#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		long long m,n,k;
		std::cin >> m >> n >> k;

		if(n>m)
			std::swap(m,n);
		long long ans = 0;
//		std::cout << m << " " << n << " " << k << " " << "\n";
		for(long long i=1;i<=m; i++)
		{
			long long x = k/i;
			if(x<=n)
				ans = std::max(ans,i*x);
			else
				ans = std::max(ans,i*n);
			if(i<=n) 
			{
				if(x<=m)
					ans = std::max(ans,i*x);
				else
					ans = std::max(ans,i*m);
			}
		}
		std::cout << ans << "\n";
	}
}



//http://www.spoj.com/problems/ATOMS/

#include <iostream>
#include <cmath>


int main()
{
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
#endif
		std::ios_base::sync_with_stdio(false);

		int t;
		std::cin >> t; 

		while(t--)
		{
				unsigned long long n,k,m;
				std::cin >> n >> k >> m;

				if(n>m)
				{
						std::cout << 0 << "\n";
						continue;
				}
//				std::cout << (unsigned long long)(log(double(m/n))/log(k)) << "\n";

				unsigned long long l=1,t=0;

				while(l<=m/n)
				{
						l*=k;
						if(l<=m/n)
							t++;
				}
				std::cout << t << "\n";
		}
}




#include <iostream>
#include <vector>
#include <queue>


bool check(long long n)
{
		while(n)
		{
				if(n%10 > 1)
						return false;
				n/=10;
		}

		return true;
}
int main()
{
		std::ios_base::sync_with_stdio(false);

		int t;
		std::cin >> t;

		while(t--)
		{
				unsigned long long n;
				std::cin >> n;

				std::queue<unsigned long long>bins;
				bins.push(1ULL);

				unsigned long long x = bins.front();
				while(x%n!=0)
				{
						bins.pop();
						bins.push(x*10);
						bins.push(x*10+1);
						x=bins.front();
				}
				std::cout << x << "\n";
		}
}

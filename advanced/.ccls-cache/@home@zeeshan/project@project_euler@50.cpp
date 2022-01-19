

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int>dp,prime;


int solve(int n)
{

}

int main()
{
		int n;
		std::cin >> n;

		std::vector<bool>check(n+5,true);
		for(int i=2;i<=sqrt(n); i++)
		{
				if(check[i])
				{
						prime.push_back(i);

						for(int j=i*2; j<=n; j+=i)
								check[j] = false;
				}
		}

		for(int i=sqrt(n)+1; i<=n; i++)
		{
				if(check[i])
						prime.push_back(i);
		}

		for(auto x : prime)
					std::cout << x << " ";
		std::cout << "\n";
		dp.resize(n,-1);
		std::cout << solve(n,0) << "\n";

		for(int i=2; i<=n; i++)
		{

		}
}

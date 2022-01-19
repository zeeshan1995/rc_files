

#include <iostream>
#include <iomanip>

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		int n;
		std::cin >> n;

		long double cost = 0.0, sell = 0.0;

		for(int i = 0; i<n; i++)
		{
			long double p, q, d;
			std::cin >> p >> q >> d;
			cost+=q*p;

			long double new_p = p + (p*d)/100.0;
			//std::cout << new_p << "}\n";
			sell+=q*(new_p - (new_p*d)/100.0);
		}

		std::cout << std::fixed << cost - sell  << "\n";
	}
}

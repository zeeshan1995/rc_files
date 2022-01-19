

#include <iostream>
#include <vector>
#include <alorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		int n;
		std::cin >> n;

		int odd = 0, even = 0;
		
		for(int i=0; i<n; ++i)
		{
			int a;
			std::cin >> a;

			if(a&1)
				++odd;
			else
				++even;
		}


	}
}

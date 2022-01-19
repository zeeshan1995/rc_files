

#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		long long B,N;
		std::cin >> N >> B;

		long long a = 1,b=0;
		long long max = 0;
		while(true)
		{
			std::cout << a <<" ";
			b=N - (a*B);
			if(b<=0)
				break;
			if(max < a*b)
				max=a*b;
			a++;
		}

		std::cout << max <<"\n";


		long long d = sqrt(N*N + 4*B*N);
		long long s = N/B;// e = (-1*N - d)/(2*B);
		

		std::cout << s <<"\n";
	}
}



#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;
std::vector<long long> pre()
{
	std::vector<long long>count(19,0);
	for(int i =1; i<10; ++i) //[ij]
	{
		for(int j=0; j<10; ++j)
			++count[9 + j - i];
	}
	return count;
}

long long modular(long long e)
{
	long long r = 1, b = 10;
	while(e > 0)
	{
		if(e&1)
			r = (r*b)%MOD;
		e >>= 1;
		b = (b*b)%MOD;
	}
	return r;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	auto count = pre();

	int t;
	std::cin >> t;

	while(t--)
	{
		long long n, w;
		std::cin >> n >> w;
		if( w>9 or w<-9 )
		{
			std::cout << "0\n";
			continue;
		}
		std::cout << (count[9+w]*modular(n-2))%MOD << "\n";
	}
}

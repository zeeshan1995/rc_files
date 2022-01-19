

#include <iostream>

int main()
{
	int a;
	std::cin >> a;

	int ans = 0;

	for(int i=1; i<=a; i+=1)
	{
		int tmp = i;

		while(tmp)
		{
			ans+=tmp%10;
			tmp/=10;
		}
	}
	std::cout << ans <<"\n";
}

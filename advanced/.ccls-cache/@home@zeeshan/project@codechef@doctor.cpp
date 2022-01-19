

#include <iostream>


int main()
{
	int n;
	std::cin >> n;

	int ans=0;
	while(n--)
	{
		int s,d;
		std::cin >> s>>d;

		if(ans<s)
		{
			ans=s;
			continue;
		}
		else
		{
			int diff = ans - s;
			if(diff < d)
				ans = ans + d - diff;
			else
				ans = (((ans - s )/d)+1)*d + s;
		}
	}

	std::cout << ans << "\n";
}

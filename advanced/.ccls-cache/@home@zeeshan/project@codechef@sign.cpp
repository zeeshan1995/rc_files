


#include <iostream>
#include <string>


int main()
{
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	std::cin >> t;

	while(t--)
	{
		std::string s;
		std::cin >> s;

		int max = 0,min = 0,sum = 0;
		for(auto x : s)
		{
			if(x == '<')
				sum++;
			else if(x == '>')
				sum--;
			if(sum > max)
				max = sum;
			if(sum < min)
				min = sum;
		}
		std::cout << std::max(1 + -1*min, 1 + max) << "\n";
	}
}

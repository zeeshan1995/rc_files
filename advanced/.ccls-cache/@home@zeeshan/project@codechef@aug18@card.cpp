
#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		std::string up, down;
		std::cin >> up >> down;

		std::vector<int>b;
		std::vector<int>o;
		for(int i=0; i<up.size(); ++i)
		{
			if(up[i] == 'b' or down[i] == 'b')
				b.push_back(i);
			if(up[i] == 'o' or down[i] == 'o')
				o.push_back(i);
		}
		bool bob = false;
		for(auto const & x : b)
		{
			for(auto const & y : o)
			{
				if(x == y)
					continue;
				for(auto const & z : b)
				{
					if(z == x or z == y)
						continue;
					bob = true;
				}
			}
		}
		if(bob)
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
}

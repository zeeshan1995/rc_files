

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;
	
	while(t--)
	{
		int n;
		std::cin >> n;

		std::vector<int>fingers(n), glove(n);

		for(auto & x : fingers)
			std::cin >> x;

		for(auto & x : glove)
			std::cin >> x;

		auto front = true, back = true;

		for(auto i=0; i<n; ++i)
		{
			if(fingers[i] > glove[i])
				front = false;
			if(fingers[n-1-i] > glove[i])
				back = false;
		}

		if(front and back)
			std::cout << "both\n";
		else if(front)
			std::cout << "front\n";
		else if(back)
			std::cout << "back\n";
		else
			std::cout << "none\n";
	}
}

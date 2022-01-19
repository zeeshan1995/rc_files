

#include <iostream>
#include <vector>
#include <array>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int>coins(n);

	for(auto & x : coins)
		std::cin >> x;

	std::array<int,4>type;
	type.fill(1e6);
	for(auto const & x : coins)
	{
		int t;
		std::cin >> t;

		if(type[t] > x)
			type[t] = x;
	}
	if(type[1]+type[2] < type[3])
		std::cout << type[1] + type[2] << "\n";
	else
		std::cout << type[3] << "\n";
}

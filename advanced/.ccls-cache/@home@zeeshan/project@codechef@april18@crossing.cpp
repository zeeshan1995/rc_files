

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> input_v(int n)
{
	std::vector<double> nums(n);

	for(auto & x : nums)
		std::cin >> x;
	return nums;
}

#define INPUT(VAR) auto VAR = input_v(n)

int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin >> t;

	while(t--)
	{
		int n;
		double s, y;
		std::cin >> n >> s >> y;

		INPUT(speed);
		INPUT(dir);
		INPUT(pos);
		INPUT(len);

		double time = 0;

		const double man_time = y/s, origin = 0;
		for(auto i=0; i<n; ++i)
		{
			double d_car = man_time * speed[i];
			if(dir[i] == 1)
			{
				auto f_pos = d_car + pos[i];
				auto b_pos = f_pos + len[i];
			}
		}
	}
}



#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	std::cin >> n;

	std::vector<std::pair<long long, long long>>data;

	for(int i=0; i<n; ++i)
	{
		int a,b;
		std::cin >> a >> b;

		data.push_back({a,b});
	}

	long long ans = 0;
	for(auto i = n-1; i>=0; --i)
	{
		auto const & a = data[i].first;
		auto const & b = data[i].second;
		ans += (b*((a+ans+b-1)/b) - a-ans);
	}

	std::cout << ans << "\n";
}

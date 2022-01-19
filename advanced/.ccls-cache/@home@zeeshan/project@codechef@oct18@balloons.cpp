

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	long long n, m;
	std::cin >> n >> m;

	std::vector<long long>tmp;

	for(decltype(n) i = 0; i<n; ++i)
	{
		long long a;
		std::cin >> a;
		tmp.push_back(a);
	}
	std::priority_queue<std::pair<long long, long long>>ballons;
	for(decltype(n) i = 0; i<n; ++i)
	{
		long long a;
		std::cin >> a;
		ballons.push({a*tmp[i], a});
	}

	while(m)
	{
		auto a = ballons.top();
		ballons.pop();
		auto b = ballons.top();
		std::cout << a.first << " ";
		auto final_q = std::min((b.first-1)/a.second, m);

		a.first-=d*a.second;
		std::cout << a.first << " ";
		ballons.push(a);
		m-=d;
	}
	std::cout << ballons.top().first << "\n";
}



#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	std::cin >> n;

	std::vector<int>quan(n);

	for(auto & x : quan)
		std::cin >> x;

	std::sort(quan.begin(), quan.end());

	std::vector<long long>sum(n);

	std::transform(quan.begin(), quan.end(), sum.begin(),
			[s=0LL] (int const x) mutable {s+=x; return s;});
#if 0
	for(auto const & x : quan)
		std::cout << x << " ";
	std::cout << "\n";
	for(auto const & x : sum)
		std::cout << x << " ";
	std::cout << "\n";
#endif

	int q;
	std::cin >> q;

	while(q--)
	{
		long long v;
		std::cin >> v;
		long long s = 0;
		int ans = (v+n-1)/n;
		auto beg = quan.begin(), end = quan.end();
		auto curr = beg;
		while(s < v and curr != end)
		{
			int left = end - curr;
			//std::cout << "left: " << left << " ";
			ans = (v - s + left - 1)/left;
			curr = std::lower_bound(beg, quan.end(), ans);
			if(curr == beg or curr == end)
				break;
			s=sum[curr - quan.begin() -1];
			beg = curr;
			//std::cout << "*curr " << *curr << " s: " << s << " ans" << ans << "\n";
		}
		//std::cout << "\n_________________\n";
		if(curr == end)
			std::cout << "-1\n";
		else
			std::cout << ans << "\n";
	}
}

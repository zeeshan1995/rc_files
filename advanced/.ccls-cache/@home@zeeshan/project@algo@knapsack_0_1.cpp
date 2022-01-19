

#include <iostream>
#include <vector>
#include <algorithm>

struct item
{
		int val;
		int w;
};

int n,max;
std::vector<item>items;

int solve(int i, int w)
{
		if(i>=n or w + items[i].w>max)
				return 0;
		else
				return std::max(items[i].val + solve(i+1, w+items[i].w),solve(i+1, w));
}

int main()
{
		std::ios_base::sync_with_stdio(false);

		freopen("input.txt", "r", stdin);
		std::cin >> n >> max;

		for(int i=0; i<n; i++)
		{
				int a,b;
				std::cin >> a >> b;
				items.push_back({a,b});
		}

		std::cout << solve(0,0) << "\n";;
}

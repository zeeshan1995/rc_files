

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

std::vector<std::array<int,3>> shop;

std::vector<int>dp;
int solve(int i, int x, int y, int z)
{
    if(i==shop.size())
        return 0;

	if(dp[i]!=-1)
		return dp[i];

    int a=0, b=0, c=0;
    if(x)
        a = solve(i+1, x-1, y, z) + shop[i][0];
    if(y)
        b = solve(i+1, x, y-1, z) + shop[i][1];
    if(z)
        c = solve(i+1, x, y, z-1) + shop[i][2];

    dp[i] = std::max({a, b, c});

	return dp[i];
}

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    int x, y, z;
    std::cin >> x >> y >> z;

  //  std::vector<std::array<int,3>> shop;

	dp.resize(n,-1);
    while(n--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        shop.push_back({a,b,c});
    }


    solve(0, x, y, z);
    std::cout << dp[0] << "\n";
}

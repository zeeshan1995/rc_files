
#include <iostream>
#include <algorithm>
#include <vector>

int solve(int i, int k, std::vector<int> const & nums, std::vector<int> & dp)
{
    if(i==nums.size()-1)
        return nums[i];
    if(dp[i])
        return dp[i];
    auto next = i + 1 + (i % k);
    if(next < nums.size())
        dp[i] = std::min(solve(i+1, k, nums, dp), solve(next, k, nums, dp)) + nums[i];
    else
        dp[i] = solve(i+1, k, nums, dp) + nums[i];
    return dp[i];
}

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
        int n, k;
        std::cin >> n >> k;

        auto nums = std::vector<int>(n+1);

        for(int i=1; i<=n; ++i)
            std::cin >> nums[i];

        std::vector<int>dp(n+1, 0);
        std::cout << solve(1, k, nums, dp) << "\n";
    }
}

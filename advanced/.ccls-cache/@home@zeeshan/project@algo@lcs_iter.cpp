


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    std::string a, b;
    std::cin >> a >> b;
    b = std::string{a.rbegin(), a.rend()};
    std::cout << b << "\n";

    std::vector<std::vector<int>> dp;
    dp.resize(a.size(), std::vector<int>(b.size(),-1));

    for(auto i=0; i<a.size(); ++i)
    {
        for(int j=0; j<b.size(); ++j)
        {
            if(a[i] == b[j])
            {
                if(i == 0 or j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1]+1;
            }
            else
                dp[i][j] = 0;
        }
    }
    for(auto x: dp)
    {
        for(auto y: x)
            std::cout << (y == -1 ? 0 : y) << "  ";
        std::cout << "\n";
    }

    int ans = 0;
    int loc = 0;
    for(int i=0; i<dp.size(); ++i)
    {
        for(int j=0; j<dp[i].size(); ++j)
        {
            if(dp[i][j] >= ans)
            {
                ans = dp[i][j];
                loc = i;
            }
        }
    }
    std::cout << ans << " " << loc << "\n";
    std::cout << std::string{a.begin()+loc-ans+1, a.begin()+loc+1} << "\n";
}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string ax, bx;
std::vector<std::vector<int>> dp;
#if 0
int lcs(std::string const &a, std::string const & b, int i=0, int j=0)
{
    std::cout << i << " " << j << "\n";
    if(i == a.size() or j == b.size())
        return 0;

//    if(dp[i][j] != -1)
  //      return dp[i][j];

    if(a[i] == b[j])
    {
        dp[i][j] = lcs(a,b,i+1,j+1) + 1;
        return dp[i][j];
    }
    //dp[i][j] = std::max(lcs(a,b,i+1,j), lcs(a,b,i,j+1));
    dp[i][j] = 0;
    lcs(a,b,i+1,j); lcs(a,b,i,j+1);
    return 0;
}
#else
int lcs(std::string const &a, std::string const & b, int i = ax.size()-1, int j=bx.size()-1)
{
    std::cout << i << " " << j << "\n";
    if(i == -1 or j == -1)
        return 0;

//    if(dp[i][j] != -1)
  //      return dp[i][j];

    if(a[i] == b[j])
    {
        dp[i][j] = lcs(a,b,i-1,j-1) + 1;
        return dp[i][j];
    }
    //dp[i][j] = std::max(lcs(a,b,i-1,j), lcs(a,b,i,j-1));
    //return dp[i][j];
    dp[i][j] = 0;
    lcs(a,b,i-1,j); lcs(a,b,i,j-1);
    return dp[i][j];
}
#endif
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    std::cin >> ax >> bx;
//    bx = std::string{ax.rbegin(), ax.rend()};
    std::cout << bx << "\n";

    dp.resize(ax.size(), std::vector<int>(bx.size(),-1));

    lcs(ax, bx);//, a.size()-1, b.size()-1);
    std::cout << dp[0][0] << "\n";
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
                loc = j;
            }
        }
    }
    std::cout << ans << " " << loc << "\n";
    std::cout << bx.substr(loc, ans) << "\n";
}

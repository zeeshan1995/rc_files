

#include <iostream>
#include <vector>
#include <string>

int main()
{
    freopen("input.txt", "r", stdin);

    std::string a;
    std::cin >> a;

    std::vector<std::vector<int>>dp(a.size(), std::vector<int>(a.size(), 0));

    for(int i=0; i<a.size(); ++i)
        dp[i][i] = 1;

    int pos=0,len=1;
    for(int i=0; i<a.size()-1; ++i)
    {
        if(a[i] == a[i+1])
        {
            dp[i][i+1] = 2;
            pos = i;
            len = 2;
        }
    }
    //return 0;
    for(int i = 3; i<=a.size(); ++i)
    {
        for(int j=0; j<=a.size() - i; ++j)
        {
            int k = j+i-1;
   //         std::cout << i << " " << j << " " << k << "\n";
            if(dp[j+1][k-1] and a[j] == a[k])
            {
                dp[j][k] = dp[j+1][k-1] + 2;
                pos = j;
                len = i;
            }
        }
    }
    std::cout << std::string{a,pos,len} << "\n";
}

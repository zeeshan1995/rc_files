
#include <iostream>
#include <string>


int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    std::cin >> t;

    long long const MOD =  1e9 + 7;

    while(t--)
    {
        long long nl, l, nr, r;
        std::cin >> nl >> l >> nr >> r;

        long long ans = 0;
        for(; l<=r; ++l)
        {
            long long b = 1;
            auto curr = std::to_string(l);
            long long sum = 0;
            for(auto i = curr.size()-1; i>0; --i)
            {
                if(curr[i] != curr[i-1])
                    sum = (sum + ((curr[i]-'0') * b)%MOD) % MOD;
                b= (b*10)%MOD;
            }

            //std::cout << l << ":" << sum + (curr[0]-'0')*b << "\n";
            ans = (ans + sum + ((curr[0]-'0')*b)%MOD)%MOD;
        }
        std::cout << ans << "\n";
    }
}

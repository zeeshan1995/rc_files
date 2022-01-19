

#include <iostream>
#include <vector>
#include <bitset>
#include <string>


int solve(int prev)
{
    //std::cout << "prev: " << prev << std::endl;

    auto bits = std::bitset<32>{prev};
    //std::cout << bits.to_string() << std::endl;
    int i=29;
    for(; i>0; i-=2)
    {
    //    std::cout << i << "->" << bits[i-1]<< " ";
        if(bits[i-1])
            break;
    }
    //std::cout << std::endl;
    if(i<0)
        return prev;

    int j=i;
    while(j&1)
    {
        for(; bits[j-1]; ++j)
            bits.flip(j-1);
        bits.flip(j-1);
    }

    for(j=i-1; j>0; --j)
    {
        if(bits[j-1])
            bits.flip(j-1);
    }
    //std::cout << bits.to_string() << std::endl;
    return bits.to_ulong();
}

int main()
{
    //std::cout << solve(5) << "\n";
    //std::cout << solve(25) << "\n";
    //std::cout << solve(35) << "\n";
    //std::cout << solve(10944) << "\n";
    //return 0;
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        long long sum = 0;
        long long prev;
        std::cin >> prev;
        sum = prev;

        for(int i=1; i<n; ++i)
        {
            long long a;
            std::cin >> a;
            if(a != -1)
            {
                prev = a;
                sum+=a;
                continue;
            }
            long long b = solve(prev);
     //       std::cout << "prev: " << prev << " new: " << b << std::endl;
            prev = b;
            sum+=b;
        }
        std::cout << sum << "\n";
    }
}

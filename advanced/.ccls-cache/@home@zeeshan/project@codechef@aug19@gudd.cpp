
#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    long long t;
    std::cin >> t;

    while(t--)
    {
        long long n;
        std::cin >> n;

        std::vector<long long> nums(n);

        for(auto & x : nums)
            std::cin >> x;

        std::vector<long long>xors{nums[0]};

        std::unordered_map<long long, std::pair<long long, long long>> xor_map;
        xor_map[xors[0]].second++;
        xor_map[xors[0]].first+=-1;

        long long ans = 0;
        for(long long i=1; i<n; ++i)
        {
            xors.push_back(xors[i-1] xor nums[i]);
            //xor_map[xors[i]];
            xor_map[xors[i]].second++;
            xor_map[xors[i]].first+=i-1;
            if(xors[i] == 0)
                ans+=i;
        }

#if 0
        for(auto & x : xor_map)
            std::cout << x.first << "->" << x.second.first << " " << x.second.second << "\n";
#endif
#if 1
        for(long long i=0; i<n; ++i)
        {
            auto it = xor_map.find(xors[i]);
            it->second.second--;
            it->second.first-=i-1;
            if(it->second.second)
                ans+=it->second.first - it->second.second * i;
        }
#endif
        std::cout << ans << "\n";
    }
}

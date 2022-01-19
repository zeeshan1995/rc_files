

#include <iostream>
#include <vector>
#include <algorithm>
#if 0
#include <chrono>
#endif

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;
#if 0
    auto start = std::chrono::high_resolution_clock::now(); 
#endif

    std::vector<int> sum(n+1, 0);
    for(int i=1; i<n+1; ++i)
    {
        int a;
        std::cin >> a;
        sum[i] = sum[i-1] + a;
    }
#if 0
    for(auto const & x : nums)
        std::cout << x << " ";
    std::cout << "\n";
    for(auto const & x : sum)
        std::cout << x << " ";
    std::cout << "\n";
#endif

    std::vector<std::pair<int,int>> ranges;

    for(int i = 1; i<n+1; ++i)
    {
        for(int j = i; j<n+1; ++j)
        {
            auto const r_sum = sum[j] - sum[i-1];
            auto const o_sum = sum[n] - r_sum;
            if(j-i+1 == n)
            {
                ranges.emplace_back(i,j);
            }
            else if( r_sum/(j-i+1) > o_sum/(n-j+i-1) )
            {
                ranges.emplace_back(i,j);
            }
        }
    }
    std::cout << ranges.size() << "\n";
    for(auto const & x : ranges)
        std::cout << x.first << " " << x.second << "\n";
#if 0
    auto end = std::chrono::high_resolution_clock::now(); 
            std::cout << "elapsed time: " << std::chrono::duration<double>{(end-start)}.count() << "s\n";
#endif
}

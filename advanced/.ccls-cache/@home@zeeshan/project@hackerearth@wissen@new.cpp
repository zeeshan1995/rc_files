

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

    std::vector<long long> nums(n)
    long long sum = 0;
    for(auto & x: nums)
    {
        std::cin >> x;
        sum+=x;
    }

    std::vector<std::pair<int,int>> ranges;

    for(int i = 0; i<n; ++i)
    {
        auto long long r_sum = 0;
        for(int j = i; j<n; ++j)
        {
            r_sum += nums[j];
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




#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;

    auto first  = std::vector<int>(n);
    auto second = std::vector<int>(m);

    auto input = [](auto & c)
    {
        for(auto & x : c)
            std::cin >> x;
    };

    input(first);
    input(second);

    auto const min_index = std::distance(first.begin(), std::min_element(first.begin(), first.end()));
    for(auto i = std::size_t{0}; i<second.size(); ++i)
        std::cout << min_index << " " << i << "\n";

    auto const max_index = std::distance(second.begin(), std::max_element(second.begin(), second.end()));
    for(auto i = std::size_t{0}; i<first.size(); ++i)
    {
        if( i != min_index )
            std::cout << i << " " << max_index << "\n";
    }
}

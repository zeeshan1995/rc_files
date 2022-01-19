

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

auto const print_v = [](auto const & v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
};


int calculate_stop(int              const   i
                  ,std::vector<int> const & edge
                  ,std::vector<int>       & stops
                  ,std::vector<bool>      & visited)
{
    std::cout << "[" << i <<" ";
    print_v(stops);

    if( visited[i] )
        stops[i] = -1;
    visited[i] = true;

    if( edge[i] == -1)
        return i;
    if( stops[i] )
        return stops[i];
    stops[i] = calculate_stop(edge[i], edge, stops, visited);
    return stops[i];
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    auto edge = std::vector<int>(n, -1);

    for(auto & x : edge)
    {
        std::cin >> x;
        --x;
    }

    auto stops = std::vector<int>(n);
    auto visited = std::vector<bool>(n, false);

    for(auto i = 0; i<n; ++i)
    {
        if( not stops[i] )
            stops[i] = calculate_stop(i, edge, stops, visited);
    }
    print_v(edge);
    print_v(stops);
}

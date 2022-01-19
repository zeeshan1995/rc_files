

#include <iostream>
#include <vector>
#include <set>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using ordered_set = tree<int,
                         null_type,
                         std::less<int>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;

int n, x, y, z;

long long result = 0;

int calculate_count(int curr, int smaller, int greater)
{
    int other_smaller = curr - smaller;
    int other_greater = n - curr - greater;

    /*
    if( x < y)
        return smaller * other_greater;
        //ans += smaller * other_greater + other_smaller * greater;
    else
        return greater * other_smaller;
        //ans += greater * other_smaller + other_greater * smaller;
    */
    auto left = smaller;
    if(x > y)
        left = greater;
    auto right = greater;
    if(y > z)
        right = other_smaller;
    return right * left;
}

void dfs(int i
        ,int p
        ,std::vector<std::vector<int>> const & g
        ,ordered_set & sides)
{
    //std::cout << i << std::endl;
    for(auto j : g[i])
    {
        if(j == p)
            continue;
        auto prev_smaller = sides.order_of_key(i);
        auto prev_greater = sides.size() - prev_smaller;

        dfs(j, i, g, sides);

        int smaller = sides.order_of_key(i) - prev_smaller;
        int greater = sides.size() - smaller - prev_greater;
        result += calculate_count(i, smaller, greater);
    }
    sides.insert(i);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
#if 1
        std::cin >> x >> y >> z;
#endif

        std::vector<std::vector<int>>g(n);

        for(int i=1; i<n; ++i)
        {
            int a, b;
            std::cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
        }
        result = 0;
        std::cout << "Input Done" << std::endl;

        ordered_set sides;
        std::vector<std::pair<int, int>> counts(n); //<smaller, greater>
        dfs(0, 0, g, sides);
        for(int i=0; i<n; ++i)
            std::cout << i << "->" << counts[i].first << " " << counts[i].second << "\n";
    }
}

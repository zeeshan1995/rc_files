


//https://www.codechef.com/APRIL19B/problems/SUBREM

#include <iostream>
#include <vector>
#include <algorithm>

int n;
long long x;
std::vector<std::vector<int>> g;
std::vector<long long>values;

long long dfs(int i, int p)
{
    long long  res = 0;
    for(auto v : g[i])
    {
        if( v != p)
            res += dfs(v, i);
    }
    return std::max(res + values[i], -x);
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
        std::cin >> n >> x;

        values.resize(n);

        for(auto & x: values)
            std::cin >> x;

        g.clear();
        g.resize(n, std::vector<int>{});

        for(int i=0; i<n-1; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
        }
        std::cout << dfs(0,-1) << "\n";
    }
}

//https://www.codechef.com/APRIL19B/problems/SJ1


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int n;
std::vector<std::vector<int>> g;
std::vector<long long>values;
std::vector<long long> mod;
std::vector<long long> result;

long long calc_gcd(long long a, long long b)
{
    if( b == 0 )
        return a;
    return calc_gcd(b, a%b);
}

void dfs(int i, int p, long long gcd)
{
    for(auto x : g[i])
    {
        if( x != p )
        {
            dfs(x, i, calc_gcd(gcd, values[x]));
        }
    }

    if(g[i].size() == 1 and i != 0)
        result[i] = mod[i] - calc_gcd(gcd, mod[i]);
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

        g.clear();
        g.resize(n);

        for(int i=1; i<n; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
        }

        values.resize(n);
        mod.resize(n);

        for(auto & x : values)
            std::cin >> x;
        for(auto & x : mod)
            std::cin >> x;

        result.clear();
        result.resize(n, -1);

        dfs(0,0,values[0]);
        for(auto const & x : result)
        {
            if( x != -1 )
                std::cout << x <<" ";
        }
        std::cout << "\n";
    }
}



//https://www.codechef.com/APRIL19B/problems/SUBREM

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>values;
std::vector<std::vector<int>> g;

long long dfs(int i)
{
  long long max = 0;
  for(auto x : g[i])
      max = std::max(max, count * std::max(solve(x, count), solve(x, count+2)));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freop("input.txt", "r", stdin);
#endif

    int t;
    std::cin >> t;

    while(t--)
    {
        int n, x;
        std::cin >> n >> x;

        values.resize(n)

        long long sum = 0;
        for(auto & x: values)
        {
            std::cin >> x;
            sum+=x;
        }

        g.resize(n, std::vector<int>);

        for(int i=0; i<n-1; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
        }
        visited.resize(n,false);
        dp.resize(n,-1);
        std::cout << solve(0, 0, sum) << "\n";
    }
}

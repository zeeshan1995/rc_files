

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, m;

template<typename T>
using d2v = std::vector<std::vector<T>>;

d2v<int> bfs(int sx, int sy, d2v<int> const & matrix)
{
    auto visited  = d2v<bool>(n, std::vector<bool>(m, false));
    auto distance = d2v<int>(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> q;

    visited[sx][sy] = true;
    q.push({sx,sy});

    auto check_and_mark = [&visited, &q, &distance](int x, int y, int u, int v)
    {
        if(u >=0 and u < n and v >=0 and v < m and not visited[u][v])
        {
            distance[u][v] = distance[x][y] + 1;
            q.push({u, v});
            visited[u][v] = true;
        }
    };

    while(not q.empty())
    {
        auto p = q.front();
        q.pop();
        auto x = p.first, y = p.second;
        auto radius = matrix[x][y];
        for(int i=0,j=radius; i<=radius and j>=0; ++i, --j)
        {
            check_and_mark(x, y, x-i, y-j);
            check_and_mark(x, y, x-i, y+j);

            check_and_mark(x, y, x+i, y-j);
            check_and_mark(x, y, x+i, y+j);
        }
    }
    return distance;
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
        std::cin >> n >> m;

        auto matrix = d2v<int>(n, std::vector<int>(m));

        for(auto & row : matrix)
        {
            for(auto & cell : row)
                std::cin >> cell;
        }

        int sx, sy;
        std::cin >> sx >> sy;

        auto distance = bfs(--sx, --sy, matrix);

        int q;
        std::cin >> q;

        while(q--)
        {
            int u, v;
            std::cin >> u >> v;

            --u;--v;
            if(u == sx and v == sy)
                std::cout << "0\n";
            else if(distance[u][v] == 0)
                std::cout << "-1\n";
            else
                std::cout << distance[u][v] << "\n";
        }
    }
}

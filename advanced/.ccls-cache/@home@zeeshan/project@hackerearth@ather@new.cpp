

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    int x, y, z;
    std::cin >> x >> y >> z;

    std::array<int,3> count{x,y,z};

    std::vector<std::array<int,3>> data;

    std::vector<bool>used(n,false);

    for(int i = 0; i<n; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        data.push_back({a,i,0});
        data.push_back({b,i,1});
        data.push_back({c,i,2});
    }

    std::sort(data.begin(), data.end(), [](auto a, auto b){return a[0] > b[0];});

    int ans = 0;

    for(auto const & d : data)
    {
        auto index = d[1];
        auto val = d[0];
        auto type = d[2];

        if(used[index] or count[type] == 0)
            continue;

        ans+=val;
        --count[type];
        used[index] = true;
    }

    std::cout << ans << "\n";
}


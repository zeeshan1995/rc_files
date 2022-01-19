

#include <iostream>
#include <vector>
#include <algorithm>

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
        int n;
        std::cin >> n;

        std::vector<int> radiation(n, 0);

        std::vector<int>count(n+1,0);

        for(auto i=0; i<n; ++i)
        {
            int a;
            std::cin >> a;
            ++count[std::max(i-a, 0)];
            --count[std::min(i+a, n-1)+1];
        }

        std::vector<int>h(n);
        for(auto & x : h)
            std::cin >> x;

        auto sum = 0;
        for(int i=0;i<n; ++i)
        {
            sum+=count[i];
            radiation[i] = sum;
        }
        /*
        for(auto const & x : count)
            std::cout << x << " ";
        std::cout << "\n";
        for(auto const & x : radiation)
            std::cout << x << " ";
        std::cout << "\n";
        */
        std::sort(radiation.begin(), radiation.end());
        std::sort(h.begin(), h.end());
        auto const it = std::mismatch(radiation.begin(), radiation.end(),
                                      h.begin(), h.end());
        if(it.first == radiation.end() and it.second == h.end())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}

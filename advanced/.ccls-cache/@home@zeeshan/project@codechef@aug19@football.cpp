#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        std::vector<int>a(n), b(n);

        for(auto & x : a)
            std::cin >> x;

        for(auto & x : b)
            std::cin >> x;

        int ans = 0;
        for(int i=0; i<n; ++i)
            ans = std::max(ans, std::max(20*a[i] - 10 * b[i], 0));
        std::cout << ans << "\n";
    }
}

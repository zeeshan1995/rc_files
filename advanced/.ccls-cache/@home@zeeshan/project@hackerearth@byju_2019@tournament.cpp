

#include <iostream>
#include <algorithm>
#include <string>

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

        std::string a, b;

        std::cin >> a >> b;

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int ans = 0;

        for(int i=0, j=0; i<a.size() and  j <b.size();)
        {
            if(a[i] == b[j])
            {
                ans++;
                ++i;++j;
            }
            else if(a[i] < b[j])
                ++i;
            else
                ++j;
        }

        std::cout << ans << "\n";
    }
}

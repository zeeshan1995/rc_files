

#include <iostream>
#include <string>
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
        std::string s;
        std::cin >> s;

        if( std::count(s.begin(), s.end(), '1') & 1 )
            std::cout << "WIN\n";
        else
            std::cout << "LOSE\n";
    }
}

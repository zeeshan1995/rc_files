

#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        long long n, k;
        std::cin >> n >> k;

        if( (n/k) % k == 0 )
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}

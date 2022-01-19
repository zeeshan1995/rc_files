
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while(t--)
    {
        long long n, p;
        std::cin >> n >> p;
        if(n==1 or n==2)
            std::cout << p*p*p << "\n";
        else
            std::cout << (p-(n-1)/2)*(p-(n-1)/2) + ((p-(n+1)/2 + 1) + (p - n))*(p-n) << "\n";
    }
}

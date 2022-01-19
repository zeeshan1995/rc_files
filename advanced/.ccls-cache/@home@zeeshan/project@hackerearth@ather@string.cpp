

#include <iostream>
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

        std::string s;

        int pre = 0;
        char prec = 'a' - 1;

        for(int i=0; i<n; ++i)
        {
            int a;
            std::cin >> a;
            if(a == pre)
            {
                s+=prec;
            }
            else if(a == pre + 1)
            {
                ++prec;
                pre = a;
                s+=prec;
            }
            else
            {
                s = "-1";
                break;
            }
        }
        std::cout << s << "\n";
    }
}


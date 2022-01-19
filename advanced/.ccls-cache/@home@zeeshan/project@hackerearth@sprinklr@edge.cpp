


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int height(int curr, int p, std::vector<int> & h, std::vector<std::vector<int>> const & g)
{
    for(auto it : g[curr])
    {
        if(it == p)
            continue;
        h[curr] = std::max(h[curr], height(it, curr, h, g));
    }
    h[curr] +=  1;
    return h[curr];
}

auto const print_v = [](auto const & v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        long long s;
        std::cin >> n >> s;
        std::vector<std::vector<int>> g(n+1);
        //g.resize(n+1);
        //h.resize(n+1, 0);
        for(int i=0, u, v ; i<n-1 ; i++)
        {
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool all_diamter = true;
        int dia = -1;
        for(int i=1; i<=n; ++i)
        {
            //std::cout << i << ":";
            std::vector<int> h(n+1, 0);
            height(i, -1, h, g);
            //print_v(h);
            //print_v(g[i]);

            int min = 1e9;
            int max = -1;
            for(auto const & x : g[i])
            {
                min = std::min(min, h[x]);
                max = std::max(max, h[x]);
            }
            if(max == min)
            {
                if(g[i].size() == 1)
                {
                    if(dia == -1)
                        dia = max;
                    if(dia != max)
                    {
                        all_diamter = false;
                        break;
                    }
                }
                else
                {
                    dia = max+min;
                    if(dia == -1)
                        dia = max + min;
                    if(dia != max+min)
                    {
                        all_diamter = false;
                        break;
                    }
                }
                continue;
            }

            //int min = *(std::min_element(g[i].begin(), g[i].end()));
            //int max = *(std::max_element(g[i].begin(), g[i].end()));
            //std::cout << "min: " << min << " max: " << max <<"\n";
            int min_count = std::count_if(g[i].begin(), g[i].end(), [&min, &h](int j){ return h[j] == min;});
            int max_count = std::count_if(g[i].begin(), g[i].end(), [&max, &h](int j){ return h[j] == max;});

        //    std::cout << max_count << " " << min_count <<"\n";
            if( dia == -1)
                dia = max + min;
            if(not (max_count + min_count == g[i].size() and max_count == 1 and max+min == dia))
            {
                all_diamter = false;
                break;
            }
        }
        //std::cout << "apple ";
        //std::cout << s << " " << n << " ";
        if( not all_diamter )
            std::cout << "0\n";
        else
            std::cout << (s + (n-1) - 1)/(n-1) << "\n";
    }
}

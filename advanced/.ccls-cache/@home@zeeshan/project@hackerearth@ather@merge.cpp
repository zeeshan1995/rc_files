

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int root(std::vector<int> & parents, int i)
{
    while(parents[i] != i)
    {
        parents[i] = parents[parents[i]];
        i = parents[i];
    }
    return i;
}

void merge(std::vector<int                >  & parents
          ,std::vector<int                >  & size
          ,std::vector<std::pair<int, int>>  & min_max
          ,int                                 a
          ,int                                 b)
{
    auto const ra = root(parents, a);
    auto const rb = root(parents, b);

    auto const min = std::min(min_max[ra].first, min_max[rb].first);
    auto const max = std::max(min_max[ra].second, min_max[rb].second);

    if(size[ra] < size[rb])
    {
        parents[ra] = parents[rb];
        size[rb] += size[ra];
        min_max[rb] = std::make_pair(min, max);
    }
    else
    {
        parents[rb] = parents[ra];
        size[ra] += size[rb];
        min_max[ra] = std::make_pair(min, max);
    }
}

template<typename T>
auto print(T const & con)
    -> decltype(std::cout << con, void())
{
    std::cout << con << " ";
}

template<typename T>
auto print(T const & con)
    -> decltype(con.first, void())
{
    std::cout << "[";
    print(con.first);
    std::cout <<",";
    print(con.second);
    std::cout << "] ";
}


template<typename T>
auto print(T const & con)
    -> decltype(con.begin(), void())
{
    for(auto const & x : con)
        print(x);
    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    std::vector<int> nums, parents, size(n,1);
    std::vector<std::pair<int, int>> min_max;

    nums.reserve(n);
    parents.reserve(n);
    min_max.reserve(n);

    for(int i=0; i<n; ++i)
    {
        int a;
        std::cin >> a;
        nums.push_back(a);
        parents.push_back(i);
        min_max.push_back({a,a});
    }
    //print(nums);
    //print(parents);
    //print(min_max);

    int q;
    std::cin >> q;

    while(q--)
    {
        int type, x;
        std::cin >> type >> x;
        --x;
        if(type == 1)
        {
            int y;
            std::cin >> y;
            --y;
            merge(parents, size, min_max, x, y);
        }
        else
        {
            auto const r = root(parents, x);
            std::cout << min_max[r].second - min_max[r].first << "\n";
        }
        //print(parents);
        //print(min_max);
        //std::cout << "---------\n";
    }
}



#include <iostream>
#include <vector>
#include <algorithm>

int root(int i
        ,std::vector<int> & roots)
{
    while(roots[i] != i)
    {
        i = roots[i];
    }
    return i;
}

int w_union(int a
           ,int b
           ,std::vector<int> & roots
           ,std::vector<int> & size
           ,std::vector<std::pair<int, int>> & min_max)
{
    auto root_a = root(a, roots);
    auto root_b = root(b, roots);
    if(root_a == root_b)
        return root_a;

    if(size[root_a] < size[root_b])
    {
        roots[root_a] = roots[root_b];
        size[root_b] += size[root_a];
        min_max[root_b].first = std::min(min_max[root_b].first, min_max[root_a].first);
        min_max[root_b].second = std::max(min_max[root_b].second, min_max[root_a].second);
        return root_b;
    }
    else
    {
        roots[root_b] = roots[root_a];
        size[root_a] += size[root_b];
        min_max[root_a].first = std::min(min_max[root_b].first, min_max[root_a].first);
        min_max[root_a].second = std::max(min_max[root_b].second, min_max[root_a].second);
        return root_a;
    }
}


int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);

    for(auto & x : nums)
        std::cin >> x;

    int q;
    std::cin >> q;

    std::vector<int>roots(n), size(n, 1);
    std::vector<std::pair<int, int>> min_max(n);

    for(int i=0; i<n; ++i)
    {
        roots[i] = i;
        min_max[i] = std::make_pair(nums[i], nums[i]);
    }

    while(q--)
    {
        int a, b;
        std::cin >> a >> b;
        auto p = w_union(--a, --b, roots, size, min_max);
        std::cout << min_max[p].first << " " << min_max[p].second << "\n";
    }
}

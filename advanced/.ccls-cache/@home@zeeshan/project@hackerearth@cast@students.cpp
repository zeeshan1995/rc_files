

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <list>

int root(int i
        ,std::vector<int> & roots)
{
    while(roots[i] != i)
    {
        roots[i] = roots[roots[i]];
        i = roots[i];
    }
    return i;
}

void w_union(int a
            ,int b
            ,std::vector<int> & roots
            ,std::vector<int> & size)
{
    auto root_a = root(a, roots);
    auto root_b = root(b, roots);
    if(root_a == root_b)
        return;

    if(size[root_a] < size[root_b])
    {
        roots[root_a] = roots[root_b];
        size[root_b] += size[root_a];
    }
    else
    {
        roots[root_b] = roots[root_a];
        size[root_a] += size[root_b];
    }
}

bool find(int a, int b, std::vector<int> & roots)
{
    return root(a, roots) == root(b, roots);
}


int main()
{
    int n, m;
    std::cin >> n >> m;

    int const N = 1e5;
    std::vector<int>roots(N), size(N, 1);
    std::iota(roots.begin(), roots.end(), 0);

    for(int i=0; i<m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        w_union(--a, --b, roots, size);
    }

    //std::unordered_map<int, std::pair<int, std:::list<int>::iterator>> counts;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> counts;
    std::list<int> q;

    while(n--)
    {
        char c;
        std::cin >> c;
        if(c =='D')
        {
            auto idx = q.front();
            q.pop_front();
            auto r = root(idx, roots);
            auto itr = counts.find(r);
            auto & p = itr->second;
            --p.first;
            if(p.first == 0)
                counts.erase(itr);
            std::cout << idx+1 << "\n";
            continue;
        }
        int a;
        std::cin >> a;
        auto r = root(--a, roots);
        auto itr = counts.find(r);
        if(itr != counts.end())
        {
            auto & p = itr->second;
            ++p.first;
            auto insert_itr = q.insert(std::next(p.second), a);
            p.second = insert_itr;
        }
        else
        {
            counts[r] = std::make_pair(1, q.insert(q.end(), a));
        }
    }
}




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int>parents;
std::unordered_map<int, bool> del;

bool mark(int i)
{
    if(i == -2)
        return false;

    auto it = del.find(i);
    if( it != del.end() and it->second )
        return true;

    auto res = mark(parents[i]);

    if( it != del.end())
    {
        if( res )
            it->second = true;
        return true;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    parents.resize(n);

    for(auto & x : parents)
    {
        std::cin >> x;
        --x;
    }
   // for(auto it : parents)
     //   std::cout << it << " ";

    //std::cout << "Done\n";

    int m;
    std::cin >> m;

    for(int i=0; i<m; ++i)
    {
        int a;
        std::cin >> a;
        del[--a] = false;
    }

  //  for(auto it : del)
    //    std::cout << it.first << "=>" << std::boolalpha << it.second << "\n";

//    std::cout << "Start processing\n";
    for(auto & it : del)
    {
 //       std::cout << it.first << " ";
        if( it.second )
            continue;
        auto res = mark(parents[it.first]);
        it.second = res;
    }
   // std::cout << "----------\n";
    auto ans = 0;
   for(auto it : del)
   {
       if( not it.second )
           ++ans;
   }
     //   std::cout << it.first << "=>" << std::boolalpha << it.second << "\n";
    std::cout << ans << "\n";
}

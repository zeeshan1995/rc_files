

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    std::cin >> n;

    auto elems     = std::vector<int>{};
    auto skip_list = std::list<int>{};
    auto map       = std::map<int, std::list<int>::iterator>{};

    int pre;
    std::cin >> pre;

    elems.push_back(pre);
    skip_list.push_back(0);
    map[0] = std::prev(skip_list.end());

    for(auto i = 1; i<n; ++i)
    {
        int a;
        std::cin >> a;
        elems.push_back(a);
        if( a == pre)
            continue;
        skip_list.push_back(i);
        map[i] = std::prev(skip_list.end());
        pre = a;
    }
    std::cout << "vector:\n";
    for(auto const & x: elems)
        std::cout << x << " ";
    std::cout << "\nskip:\n";
    for(auto const & x: skip_list)
        std::cout << x << " ";
    std::cout << "\nmap:\n";
    for(auto const & [x, y]: map)
        std::cout << "[" << x << "=> " << *y << "]\n";

    int q;
    std::cin >> q;

    while(q--)
    {
        //std::cout << q << " here \n";
        int a, pos;
        std::cin >> a >> pos;
        if(a == 1)
        {
            int val;
            std::cin >> val;
            if( elems[pos] == val )
                continue;
            auto const not_less = map.lower_bound(pos);
            if( not_less != map.end() )
            {
                if( (*not_less).first == pos )
                {
                    if( elems[pos-1] == val )
                    {

                    }
                }
            }
        }
        else
        {
            //std::cout << a << " " << pos << "\n";
            auto const not_less = map.lower_bound(pos);
            //if( not_less == map.end() )
            //    std::cout << "index of vec from map [end]" << (*not_less).first << "\n";
            //else
            //    std::cout << "index of vec from map " << (*not_less).first << "\n";
            auto const skip_itr = [&]()
            {
                if( not_less == map.end() )
                    return skip_list.end();
                return (*not_less).second;
            }();
            //std::cout << "index of vec from skip_list " << *skip_itr << "\n";
            //if( (skip_itr == skip_list.begin())  or (skip_itr != skip_list.end() and *skip_itr == pos) )
            if( (skip_itr != skip_list.end() and *skip_itr == pos) )
                std::cout << *skip_itr << "\n";
            else
            {
         //       std::cout << "here\n";
                auto const prev_itr = std::prev(skip_itr);
                //if( prev_itr == skip_list.end() )
                //    std::cout << "error\n";
                //else
                //    std::cout << *prev_itr << "\n";
                
                std::cout << (*prev_itr) << "\n";
                //if( prev_itr == skip_list.begin() )
                //    std::cout << (*prev_itr) << "\n";
                //else
                //    std::cout << (*prev_itr) + 1 << "\n";
            }
        }
    }
}

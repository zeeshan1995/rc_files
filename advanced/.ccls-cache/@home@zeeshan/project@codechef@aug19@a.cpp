

#include <iostream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using ordered_set = tree<int,
                         null_type,
                         std::less<int>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;

int main()
{
    std::vector<std::pair<int, int>> v(10);

    for(auto const & x : v)
        std::cout << x.first << " " << x.second <<"\n";
	ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

	std::cout<<*X.find_by_order(1)<<std::endl; // 2
    std::cout<<*X.find_by_order(2)<<std::endl; // 4
    std::cout<<*X.find_by_order(4)<<std::endl; // 16
    std::cout<<(end(X)==X.find_by_order(6))<<std::endl; // true
	
	std::cout<<X.order_of_key(4)<<std::endl;   // 2
}

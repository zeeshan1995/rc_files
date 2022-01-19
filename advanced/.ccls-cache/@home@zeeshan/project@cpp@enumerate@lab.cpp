
#include "enumerate.hpp"


#include <iostream>
#include <vector>


int main()
{
    std::vector<int>nums{1,2,3,4,5};
#if 0
    auto x = loop_element_t{nums.begin(), 0};
    std::cout << x.value() << " " << x.index() << "\n";
    ++x;
    std::cout << x.value() << " " << x.index() << "\n";
    auto y = x;
    ++y;
    if(x != y)
        std::cout << "Not equal\n";
    for(auto x : enumerate_t{nums})
        std::cout << x.value() << " " << x.index() << "\n";
#endif
#if 0
    for(auto x : enumerate(nums))
        std::cout << x.value() << " " << x.index() << "\n";
#endif
    for(auto [value,index] : enumerate(nums))
    {
        std::cout << value << " " << index << "\n";
        value = 23;
    }
    for(auto  [value,index] : enumerate(nums))
        std::cout << value << " " << index << "\n";

    //auto [x,y] = std::pair<int,char>{1,'s'};
}

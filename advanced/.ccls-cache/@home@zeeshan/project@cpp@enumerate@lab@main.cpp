
#include <enumerate.hpp>


#include <iostream>
#include <vector>

int main()
{
    std::vector<int>nums{1,2,3,4,5};
    for(auto  [value,index] : enumerate(nums))
        std::cout << value << " " << index << "\n";
}

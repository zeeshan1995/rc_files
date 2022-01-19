
#include <stl_adaptor/algorithm.hpp>

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums {2, 1, 2, 3, 4, 5, 2, 3, 4, 2};
#if 0
    {
        auto first = nums.begin();
        while( first != nums.end() )
        {
          auto x = stl_adaptor::find(first, std::distance(first, nums.end()), 2);
          std::cout << "Index => [" << x.second << "]\n";
          std::cout << "Elem  => [" << *x.first << "]\n-------\n";
          first = x.first;
          if( x.second )
              ++first;
        }
    }
#endif

#if 0
    {
    auto first = nums.begin();
    auto last = nums.end();

    auto n = std::size_t{1};

    while(first != last)
    {
        first = stl_adaptor::find_nth(nums.begin(), last, 2, n);
        auto index = std::distance(nums.begin(), first);
        std::cout << "nth   => [" << n << "]\n";
        std::cout << "Index => [" << index << "]\n";
        std::cout << "Elem  => [" << nums[index] << "]\n-------\n";
        ++n;
    }
    }
#endif
#if 1
    {
        auto n = std::size_t{1};
        auto used = std::size_t{1};
        while( used )
        {
            auto x = stl_adaptor::find_nth(nums.begin(), nums.size(), 2, n);
            std::cout << "nth   => [" << n << "]\n";
            //std::cout << "Index => [" << nums.size() - x.second << "]\n";
            std::cout << "Index => [" << x.second << "]\n";
            std::cout << "Index => [" << std::distance(x.first, nums.end()) << "]\n";
            std::cout << "Elem  => [" << *x.first << "]\n-------\n";
            ++n;
            used = x.second;
        }
    }
#endif
}

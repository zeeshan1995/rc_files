

#include <iostream>
#include <vector>



template<typename Iterator, typename Callable1, typename Callable2>
Iterator binary_search(Iterator first
                      ,Iterator last
                      ,Callable1 go_left
                      ,Callable2 go_right)
{
    auto curr_first = first;
    auto curr_last = last;

    while(curr_first != curr_last)
    {
        auto d = std::distance(curr_first, curr_last);
        auto mid = curr_first + d/2;
#if 0
        std::cout << std::distance(first, curr_first) 
                  << " " 
                  << std::distance(first, mid)
                  << " "
                  << std::distance(first, curr_last) <<"\n";
#endif
        if( go_left(curr_first, mid, curr_last) )
            curr_last = mid;
        else if( go_right(curr_first, mid, curr_last) )
            curr_first = mid+1;
        else
            return mid;
    }
    return last;
}

int main()
{
    std::vector<int> nums  = {1,2,3,4,5,6,7,8,9};
    //std::vector<int> nums = {4,5,6,7,0,1,2};
    for(auto const & x : nums)
    {
        auto it = binary_search(nums.begin()
                               ,nums.end()
                               ,[](auto first, auto mid, auto last){return *first < *mid and *last > *mid;}
                               ,[](auto first, auto mid, auto last){return *first < *mid and *last < *mid;});
        std::cout << x << "=> " << std::distance(nums.begin(),it) << "\n";
    }
}

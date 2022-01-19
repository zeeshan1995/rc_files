

std::vector<T>
descending ascending
T is <;
vector is not empty

Find the minimum;

readable


Time: No limit

===========================================================

template<typename T>
std::size_t min(std::vector<T> const & nums)
{
    auto itr = std::adjacent_find(nums.begin()
                                 ,nums.end()
                                 ,[](T const & left, T const & right)
                                 {
                                     return left < right;
                                 });
    if(itr == nums.end())
        return nums.size()-1;
    return std::distance(nums.begin()
                        ,itr);
}

/*
 10, 9, 8, 8, 8, 7, 6, 6, 6, 9, 10, 11, 12, 13 : Which index
 10, 9, 8, 8, 8, 7, 6, 6, 6, 1, 2, 3, 4, 5
 10, 9, 8, 8, 8, 7, 6, 6, 6
 9, 10, 11, 12, 13
 9
*/


#include <iostream>
#include <vector>
#include <algorithm>

/*
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
*/
template<typename T>
std::size_t min(std::vector<T> const & nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while(start < end)
    {
        int mid = (start+end)/2;
        std::cout << start << " " << mid << " " << end << "\n";
        if(nums[mid] < nums[mid+1] and nums[mid-1] < nums[mid])
            end = mid;
        else if(nums[mid+1] < nums[mid] and nums[mid] < nums[mid+1])
            start = mid + 1;
        else if(nums[mid] < nums[mid+1] and  nums[mid-1] < nums[mid-1])
            return mid-1;
        else return mid;
    }
    return start;
}


int main()
{
    std::cout << "hello\n";
    std::vector<int> nums{9, 8, 7, 6, 9, 10, 11, 12, 13};
    std::vector<int> nums1{9, 8, 7, 6, 1, 2, 3};
    std::vector<int>nums2{9, 8, 6, 7};
    std::vector<int>nums3{9, 10, 11, 12, 13};
    std::vector<int>nums4{9};

    std::cout << nums[min(nums)] << "\n";
    std::cout << nums1[min(nums1)] << "\n";
    std::cout << nums2[min(nums2)] << "\n";
    std::cout << nums3[min(nums3)] << "\n";
    std::cout << nums4[min(nums4)] << "\n";
}

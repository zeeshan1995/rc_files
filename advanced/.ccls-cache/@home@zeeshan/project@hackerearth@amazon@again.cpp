

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <numeric>

std::unordered_map<int, int> solve(std::vector<int> const & nums)
{
    std::vector<int> prev = nums;
    std::unordered_map<int,int>result;
    while(prev.size() > 1)
    {
        std::cout << prev.size() << " ";
        std::vector<int>cur_or;
        for(int i=0; i<prev.size()-1; ++i)
        {
            cur_or.push_back(prev[i] | prev[i+1]);
            ++result[cur_or.back()];
        }

        /*
        std::sort(cur_or.begin(), cur_or.end());
        std::merge(result.begin(), result.end()
                  ,cur_or.begin(), cur_or.end()
                  ,std::back_inserter(temp_result));
        result = temp_result;
        */

        prev = cur_or;
    }
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> nums(n);
        std::iota(nums.begin(), nums.end(), 1);

        //for(auto & x : nums)
        //    std::cin >> x;

        auto result = solve(nums);
        std::cout << "Done\n";

        std::cout << result.size() << " " << (n*(n+1))/2 << "\n";
        
        /*
        int q;
        std::cin >> q;

        while(q--)
        {

        }
        */
    }
}


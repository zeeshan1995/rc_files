


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


int main()
{
    int t;
    std::cin >> t;

    while(t--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> nums(n, std::vector<int>(m));

        for(auto & row : nums)
        {
            for(auto & elem : row)
                std::cin >> elem;
        }

        auto result = std::accumulate(nums.cbegin()
                                     ,nums.cend()
                                     ,std::pair<int, int>{0, 0}
                                     ,[m](auto sum, auto const & row)
                                     {
                                        std::get<0>(sum) += *std::max_element(row.cbegin(), row.cbegin()+m/2);
                                        std::get<1>(sum) += *std::max_element(row.cbegin()+m/2, row.cend());
                                        std::swap(std::get<0>(sum), std::get<1>(sum));
                                        return sum;
                                     });

        std::cout << std::max(std::get<0>(result), std::get<1>(result)) << "\n";
    }
}

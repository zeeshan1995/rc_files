


#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int>trans{5000, -400, 1000, 1000, 500, -200, 500, -100};
    std::vector<std::pair<int, int>> inr{{5000,5000}};

    std::transform(trans.begin()+1
                  ,trans.end()
                  ,std::back_inserter(inr)
                  ,[&](int t)
                  {
                    return std::make_pair(t, inr.back().second + t);
                  });

    for(auto const & x : inr)
        std::cout << x.first << " " << x.second << "\n";

    int const rate = 70;
    std::vector<std::pair<int, int>> usd{{5000,5000 * rate}};
    std::transform(trans.begin()+1
                  ,trans.end()
                  ,std::back_inserter(usd)
                  ,[&](int t)
                  {
                    return std::make_pair(t, usd.back().second + t*rate);
                  });

    for(auto const & x : usd)
        std::cout << x.first << " " << x.second << "\n";

}

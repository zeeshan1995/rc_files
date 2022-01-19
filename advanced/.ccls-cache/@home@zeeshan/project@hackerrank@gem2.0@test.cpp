

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

std::vector<int> climbingLeaderboard(std::vector<int> scores, std::vector<int> alice) {
    std::sort(scores.begin(), scores.end());

    auto last = std::unique(scores.begin(), scores.end());
    for(auto const x : scores)
        std::cout <<x << " ";

    std::vector<int> ans(alice.size(), 0);
    int i=0;
    for(auto const & x : alice)
    {
        auto const p = std::lower_bound(scores.begin(), last, x);
        int rank = std::distance(p, last);
        std::cout << "[" << *p << " " << rank <<"]";
        if(*p == x)
            ans[i] = rank;
        else
            ans[i] = rank+1;
        ++i;
    }
    return ans;

 //   std::vector<std::tuple<int, int, int>> fscores;

 //   for(int i=0; i<scores.size(); ++i)
 //   {
 //       fscores.emplace_back(scores[i], i, 0);
 //   }
 //   for(int i=0; i<alice.size(); ++i)
 //   {
 //       fscores.emplace_back(alice[i], i, 1);
 //   }
////    for(auto const x : fscores)
////        std::cout <<std::get<0>(x) << " " << std::get<1>(x) << " " << std::get<2>(x) << "\n";
////
 //   std::sort(fscores.begin(), fscores.end(), [](auto const a, auto const b){ return std::get<0>(a) > std::get<0>(b); });

////    for(auto const x : fscores)
////        std::cout <<std::get<0>(x) << " " << std::get<1>(x) << " " << std::get<2>(x) << "\n";
 //   std::vector<int> ans(alice.size(), 0);

 //   int rank = 1;
 //   long long pre = std::get<0>(fscores.front());
 //   for(auto const x : fscores)
 //   {
 //       int score = std::get<0>(x);
 //       int index = std::get<1>(x);
 //       int person = std::get<2>(x);
 //       if(pre != score)
 //           ++rank;
 //       std::cout << pre << " " <<rank << " " << score << " " << index << " " << person << "\n";
 //       pre = score;
 //       if(person)
 //           ans[index] = rank;
 //   }
 //   return ans;
}//


int main()
{
    auto a = std::vector<int>{34, 64, 1, 67, 10, 24};

    //std::sort(a.begin(), a.end(), [](auto a, auto b){return a> b;});
    //for(auto const & x : a)
    //    std::cout << x << " ";
    //std::cout << "\n";
    std::vector<int>scores{100,90,90,80};
    std::vector<int>alice{70, 80,105};
    auto const ans = climbingLeaderboard(scores, alice);
    for(auto const & x : ans)
        std::cout << x << " ";
    std::cout << "\n";
}

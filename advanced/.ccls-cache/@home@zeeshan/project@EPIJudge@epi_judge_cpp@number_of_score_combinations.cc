#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

/*
 * this give all number of sequences
 * But the problem aske --> disctinct number of combination like for 9 --> seq is [2,7], [7,2] but combination is [2,7]
int solve(int score, const vector<int>& individual_play_scores, std::vector<int> & dp)
{
    if(score < 0)
        return 0;
    if(dp[score] != -1)
        return dp[score];
    auto count = 0;
    for(auto x : individual_play_scores)
        count += solve(score-x, individual_play_scores, dp);
    dp[score] = count;
    return count;
}
*/
int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  // TODO - you fill in here.
    std::vector<std::vector<int>>dp(final_score+1, std::vector<int>(individual_play_scores.size(), 0));
    std::fill(dp.front().begin(), dp.front().end(), 1);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.cc",
                         "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}

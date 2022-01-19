#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int solve(int i, int j, std::string const A, std::string const & B,  std::vector<std::vector<int>> & dp)
{
    if(i >= A.size())//insert extras
        return B.size()-j;
    if(j >= B.size()) //delete extra from A
        return A.size()-i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(A[i] == B[j])
        dp[i][j] = solve(i+1, j+1, A, B, dp);
    else
        dp[i][j] = std::min({solve(i+1, j+1, A, B, dp), //subs
        solve(i, j+1, A, B, dp), //insert
        solve(i+1, j, A, B, dp)}) + 1; //deletion
    return dp[i][j];
}
int LevenshteinDistance(const string& A, const string& B) {
  // TODO - you fill in here.
  std::vector<std::vector<int>>dp(A.size(), std::vector<int>(B.size(),-1));
  return solve(0, 0, A, B, dp);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.cc",
                         "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}

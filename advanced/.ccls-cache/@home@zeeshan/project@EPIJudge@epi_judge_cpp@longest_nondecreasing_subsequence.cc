#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int LongestNondecreasingSubsequenceLength(const vector<int>& A) {
  // TODO - you fill in here.
  std::vector<int>res(A.size(), 1);
  for(int i=0;i<A.size(); ++i)
  {
	  for(int j=i+1; j<A.size(); ++j)
	  {
		  if(A[j] >= A[i])
			  res[j] = std::max(res[i]+1, res[j]);
	  }
  }

  return *std::max_element(res.begin(), res.end());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "longest_nondecreasing_subsequence.cc",
                         "longest_nondecreasing_subsequence.tsv",
                         &LongestNondecreasingSubsequenceLength,
                         DefaultComparator{}, param_names);
}

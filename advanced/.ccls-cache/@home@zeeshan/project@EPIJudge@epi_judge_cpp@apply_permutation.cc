#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
void ApplyPermutation(vector<int> perm, vector<int> & A) {
  // TODO - you fill in here.
  for(int i=0; i<perm.size(); ++i)
  {
      auto curr = A[i], j = i;
      while(perm[j]!=-1)
      {
          auto next = A[perm[j]];
          A[perm[j]] = curr;
          auto tmp = perm[j];
          perm[j] = -1;
          j = tmp;
          curr = next;
      }
  }
}
vector<int> ApplyPermutationWrapper(const vector<int>& perm, vector<int> A) {
  ApplyPermutation(perm, A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}

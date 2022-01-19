#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> NextPermutation(vector<int> perm) {
  // TODO - you fill in here.
  int max = perm.size()-1;
  for(int i=perm.size()-1; i>=0; --i)
  {
      std::cout << i << " ";
      if(perm[i] < perm[max])
      {
          std::swap(perm[i], perm[max]);
          break;
      }
      else
          max = i;
  }
  std::cout << std::endl;
  if(max == 0)
      return {};
  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}

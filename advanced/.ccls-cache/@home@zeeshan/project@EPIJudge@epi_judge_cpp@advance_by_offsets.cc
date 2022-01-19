#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {
  // TODO - you fill in here.
  int max = 0;
  for(int i=0; i<max_advance_steps.size() and max < max_advance_steps.size()-1 and max>=i ; ++i)
      max = std::max(max, i+max_advance_steps[i]);
  return max>=max_advance_steps.size()-1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}

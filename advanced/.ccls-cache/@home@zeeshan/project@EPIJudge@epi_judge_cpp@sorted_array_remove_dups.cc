#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;
// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>& A) {
  // TODO - you fill in here.
  //return std::distance(A.begin(), std::unique(A.begin(), A.end()));
  if(A.empty())
      return 0;
  auto end = 1;
  while(end < A.size() and A[end]!=A[end-1])
      ++end;
  std::cout << end << "\n";
  for(int i=end+1; i<A.size() and end < A.size(); ++i)
  {
      if(A[i]!=A[end-1])
          A[end++]=A[i];
  }
  return end;
}
vector<int> DeleteDuplicatesWrapper(TimedExecutor& executor, vector<int> A) {
  int end = executor.Run([&] { return DeleteDuplicates(A); });
  A.resize(end);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "sorted_array_remove_dups.cc", "sorted_array_remove_dups.tsv",
      &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
}

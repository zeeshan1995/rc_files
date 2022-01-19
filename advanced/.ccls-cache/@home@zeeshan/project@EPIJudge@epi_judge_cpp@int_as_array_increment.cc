#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  // TODO - you fill in here.
  int carry = 1;
  std::transform(A.rbegin(), A.rend(), A.rbegin(), [&carry](int a) { return a+=carry,carry=a>9,a%=10,a;});
  if(carry)
      A.insert(A.begin(), carry);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}

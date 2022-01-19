#include <string>

#include "test_framework/generic_test.h"
#include <cmath>
using std::string;

void binary(int n, std::string & res)
{
    if(n/26 != 0)
        binary(n/26, res);
    res+=('A' + n%26);
}
int SSDecodeColID(const string& col) {
  // TODO - you fill in here.
  int base = 1;
  return std::accumulate(col.rbegin(), col.rend(), 0, [&base](int a, char c) {int x = a+base*(c-'A'+1);base*=26;return x;});
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"col"};
  return GenericTestMain(args, "spreadsheet_encoding.cc",
                         "spreadsheet_encoding.tsv", &SSDecodeColID,
                         DefaultComparator{}, param_names);
}

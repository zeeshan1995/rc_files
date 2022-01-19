#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include <algorithm>

using std::string;

string IntToString(int x) {
  // TODO - you fill in here.
  bool is_negative = false;
  if (x < 0) {
    is_negative = true;
  }

  string s;
  do {
    s += '0' + abs(x % 10);
    x /= 10;
  } while (x);

  s += is_negative ? "-" : "";  // Adds the negative sign back if is_negative.
  return {rbegin(s), rend(s)};
}
int StringToInt(const string& s) {
  // TODO - you fill in here.
  if(s.empty())
      return 0;
  auto begin = s.begin();
  if(*begin == '-' or *begin =='+')
      ++begin;
  auto num = std::accumulate(begin, s.end(), 0, [](int a, char b) { return a*10 + (b - '0');});
  return s[0] == '-' ? -num : num;
}
void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}

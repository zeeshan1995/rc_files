#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;

void ReverseWords(string* s) {
  // TODO - you fill in here.
    std::reverse(s->begin(), s->end());
    auto beg = s->begin(), end = std::find(s->begin(), s->end(), ' ');
    while(end != s->end())
    {
        std::reverse(beg, end);
        beg = std::next(end);
        end = std::find(beg, s->end(), ' ');
    }
    std::reverse(beg, end);
}
string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}

#include <string>
#include <unordered_set>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;
using std::unordered_set;

int TransformString(unordered_set<string> D, const string& s, const string& t) {
  // TODO - you fill in here.

    std::unordered_map<std::string, std::vector<string>>graph;
    D.erase(s);

    std::queue<std::pair<std::string, int>>q;
    q.push({s,0});
    while(not q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(cur.first == t)
            return cur.second;

        for(int i=0; i<cur.first.size(); ++i)
        {
            auto x = cur.first;
            for(char c='a'; c<='z'; ++c)
            {
                x[i] = c;
                auto it=D.find(x);
                if(it != D.end())
                {
                    D.erase(it);
                    q.push({x, cur.second+1});
                }
            }
        }
    }
  return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}

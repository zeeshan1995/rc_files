

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include <unordered_map>

int solve(std::string const & str)
{
    std::unordered_map<char, int> pos;
    int len = 0, i = 0, j = 0;
    while(i < str.size() and  j < str.size())
    {
        auto const c = str[j];

        if( not pos.count(c) or pos[c] < i)
        {
            len = std::max(len, j - i + 1);
            pos[c] = j;
            ++j;
            continue;
        }
        else
            ++i;
        //len = std::max(len, i - std::max(pos[c], last_pos));
        //pos[c] = i;
        //last_pos = i;
        //std::cout << i << "=>" << len << "\n";
    }
    return len;
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << "\n";
}

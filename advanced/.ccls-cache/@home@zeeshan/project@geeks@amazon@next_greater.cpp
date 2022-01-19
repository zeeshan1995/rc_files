

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

int main()
{
    int n = 8;
    std::vector<int> nums;
    nums.emplace_back(6);
    nums.emplace_back(5);
    nums.emplace_back(4);
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(5);
    nums.emplace_back(2);
    nums.emplace_back(7);

    std::stack<int> next;
    std::vector<int>res;

    for(int i=n-1; i>=0; --i)
    {
        while(not next.empty() and next.top() < nums[i])
            next.pop();
        if(next.empty())
            res.push_back(-1);
        else
            res.push_back(next.top());
        next.push(nums[i]);
    }

    std::cout << res.size() << "\n";
    std::copy(res.rbegin(), res.rend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<< std::endl;
}

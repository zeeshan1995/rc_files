


/*
 * Given three integers a, b, c, return any string s which satisfies following conditions: 1) A string is a valid string if it doesn't contain aaa, bbb, ccc as a substring. 2)
 * string has to a longest possible string. 2) s contains at most a occurences of letter 'a', at most b occurences of letter 'b', and at most c occurences of letter 'c'. 3) s will
 * only contain 'a', 'b' and 'c'. If there is no such string s return empty string. Ex: Input: a = 1, b = 1, c=7 output: ccaccbcc or ccbccacc Input : a = 2, b= 2, c = 1 output:
 * aabbc Input: a = 7, b = 1, c=0 output: aabaa 
 * */


#include <string>

std::string gen_string(int a, int b, int c)
{
    std::string res = "";
    bool added = true;
    auto check = [](int &z, std::string & res, char add, int nums)
    {
        if(!res.empty() and res.back()!=add and z>0)
        {
            res+=std::string(add, std::min(nums, z));
            z-=nums;
            return true;
        }
        return false;
    };

    std::vector<std::pair<int, char>>{{a, 'a'} ,{b, 'b'} ,{c, 'c'}};
    while((a>0 or b>0 or c>0) and added)
    {
        std::sort(chars.begin(), chars.end(), [](auto a, auto b){return a.first>b.first});
        added = false;
        added = added || check(chars[0].first, res, chars[0].second, 2);
        added = added || check(chars[1].first, res, chars[1].second, 1);
    }

}
a =1 ;
b = 1;
c = 7;

a->4, b=3; c=0;
aab ==> a->2, b->2
aabaab == a->0, b->1

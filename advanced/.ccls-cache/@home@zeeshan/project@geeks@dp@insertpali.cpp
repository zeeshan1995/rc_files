

//http://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/

#include <iostream>
#include <string>

std::string s = "geeks";
int solve(int i,int j)
{
	if(i>=j)
		return 0;
	if(s[i]==s[j])
		return solve(i+1,j-1);
	return std::min(solve(i+1,j)+1,solve(i,j-1)+1);
}
int main()
{
	std::cout << solve(0,s.size()-1) <<"\n";
}

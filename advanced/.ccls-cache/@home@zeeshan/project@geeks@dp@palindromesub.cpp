

#include <iostream>
#include <string>
std::string s = "GEEKSFORGEEKS";

int solve(int i,int j)
{
	if(i==j)
		return 1;
	if(i>j)
		return 0;
	if(s[i]==s[j])
		return solve(i+1,j-1)+2;
	else
		return std::max(solve(i+1,j), solve(i,j-1));
}

int main()
{

	std::cout <<solve(0,s.size()-1) <<"\n";
}



//http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/


#include <iostream>
#include <vector>

std::string s1,s2;

int solve(int i, int j)
{
	if(i==s1.size())
		return s2.size()-j;
	if(j==s2.size())
		return s1.size()-i;
	if(s1[i]==s2[j])
		return solve(i+1,j+1);
	else
		return std::min(solve(i+1,j+1)+1, //replace
				std::min(solve(i,j+1)+1,//insert
					solve(i+1,j)+1));//remove
}
int main()
{
	std::cin >>s1 >> s2;

	std::cout <<solve(0,0);
}

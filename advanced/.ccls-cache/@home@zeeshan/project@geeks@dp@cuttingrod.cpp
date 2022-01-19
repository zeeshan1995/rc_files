

#include <iostream>
#include <iostream>
#include <vector>

std::vector<int>price ={1,5,8,9,10,17,17,20};

int solve(int i,int l)
{
	if(l<=0 or i>=price.size())
		return 0;
	if(l-i-1>=0)
	return std::max(solve(i+1,l),solve(i,l-i-1)+price[i]);
	else
		return solve(i+1,l);
}
int main()
{

	int n = price.size();

	std::cout << solve(0,n);
}

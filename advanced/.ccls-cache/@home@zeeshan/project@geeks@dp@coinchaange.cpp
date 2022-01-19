

#include <iostream>
#include <vector>

std::vector<int>coins = {2,5,3,6};
int solve(int n,int i)
{
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(i>=coins.size())
		return 0;

	return solve(n,i+1) + solve(n-coins[i],i);
}
int main()
{

	int n=10;

	std::cout<<solve(n,0) << "\n";
}

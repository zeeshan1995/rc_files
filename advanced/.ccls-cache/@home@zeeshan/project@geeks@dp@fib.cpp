

//http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/


#include <iostream>
#include <vector>
std::vector<int>dp;

int solve(int n)
{
	if(dp[n]!=-1)
		return dp[n];
	return dp[n] = solve(n-1) + solve(n-2);
}
int main()
{
	int n;
	std::cin >>n;

	dp.resize(n+1,-1);
	dp[0]=0;
	dp[1]=1;

	std::cout << solve(n) << "\n";
}

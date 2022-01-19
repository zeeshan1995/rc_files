
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int n,k;
std::vector<int>nums,dp;

int solve(int i)
{
	if(i >=n)
		return 0;
	if(dp[i]!=-1)
		return dp[i];
	dp[i] = std::max(nums[i] + solve(i+k+1),solve(i+1));
	return dp[i];
}

int main()
{

	std::string s;
	std::cin >> s;

	std::istringstream ss(s);
	std::string token;

	std::getline(ss,token,',');
	n = atoi(token.c_str());
	std::getline(ss,token,',');
	k = atoi(token.c_str());

	nums.resize(n);

	for(int i=0; i<n; i++)
		std::cin >> nums[i];
	
	dp.resize(n,-1);
	std::cout << solve(0) <<"\n";
}

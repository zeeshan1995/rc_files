

#include <iostream>
#include <vector>
#include <algorithm>
int n;
int a,b,c;

std::vector<std::vector<int>>dp(105,std::vector<int>(3,-1));

int index(char d)
{
	if(d=='r')
		return 0;
	if(d=='o')
		return 1;
	if(d=='e')
		return 2;
}
int solve(int x,char d)
{
	if(x>=n)
		return 0;
	if(dp[x][index(d)]!=-1)
		return dp[x][index(d)];
	int ans;
	if(d=='r')
		ans = std::min(solve(x+1,'o')+a,solve(x+1,'e')+b);
	if(d=='o')
		ans = std::min(solve(x+1,'r')+a,solve(x+1,'e')+c);
	if(d=='e')
		ans = std::min(solve(x+1,'r')+b,solve(x+1,'o')+c);
	dp[x][index(d)]=ans;
	return ans;
}
int main()
{
	std::cin >> n >> a>>b>>c;
	std::cout <<solve(1,'r')<< "\n";
}

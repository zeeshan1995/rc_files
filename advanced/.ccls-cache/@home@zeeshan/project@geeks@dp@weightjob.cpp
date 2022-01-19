

//http://www.geeksforgeeks.org/weighted-job-scheduling/
//

#include <iostream>
#include <vector>
std::vector<int>start = {3,1,6,2},end = {10,2,19,100},profit = {20,50,100,200};

int solve(int i,int pre)
{
	if(i>=start.size())
		return 0;
	else if(pre==-1 or start[i] >=end[pre])
		return std::max(solve(i+1,i)+profit[i], solve(i+1,pre));
	else
		return solve(i+1,pre);
}
int main()
{
	std::cout<< solve(0,-1) << "\n";
}

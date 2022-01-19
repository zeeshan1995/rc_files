

//http://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/


#include <iostream>
#include <vector>

std::vector<int>score = {3,5,10};

int solve(int i,int n)
{
	if(n==0)
		return 1;
	if(i>=score.size())
		return 0;
	if(score[i]<=n)
		return solve(i+1,n)+solve(i,n-score[i]);
	return solve(i+1,n);
}
int main()
{

	std::cout <<solve(0,13) << "\n";
}

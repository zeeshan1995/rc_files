

#include <iostream>
#include <vector>

int n;

int solve(int i)
{
	if(i==n)
		return 1;
	if(i>n)
		return 0;
	return solve(i+2) + solve(i+1);
}
int main()
{
	n=4;
	std::cout <<solve(0)<<"\n";
}

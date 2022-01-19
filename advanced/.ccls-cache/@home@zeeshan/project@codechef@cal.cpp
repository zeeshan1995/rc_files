

#include <iostream>
#include <vector>
#include <algorithm>


int solve(int n, int b,int x, int y)
{
	if(n >=b)
		return std::max(

int main()
{
	int n,b;
	std::cin >> n >> b;

	std::cout << solve(n,b,0,0);
}

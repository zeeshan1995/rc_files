

#include <iostream>
#include <vector>

int n,m;

int solve(int sum , int n)
{
	if(sum==0 and n==0)
		return 1;
	if(sum<=0 or n<=0)
		return 0;
	int tmp=0;
	for(int i=1;i<=m; i++)
		tmp+=solve(sum-i,n-1);
	return tmp;

}
int main()
{
	int sum;
	std::cin >> n >> m >> sum;

	std::cout <<solve(sum,n)<< "\n";
}



#include <iostream>
#include <vector>
#include <algorithm>

	int n;
std::vector<int>nums;
void solve(int d,int s)
{
//	std::cout << d << " ";
	for(int i=0;i<10;i++)
	{
		int x = d*10+i,y=s+i;
		if(x+y>n)
			break;
		else if(x+y==n)
		{
			nums.push_back(x);
			break;
		}
		solve(x,y);
	}
}
int main()
{
	std::cin >> n;
	for(int i=1;i<10;i++)
		solve(i,i);
	std::sort(nums.begin(),nums.end());
	std::cout << nums.size() <<"\n";
	for(auto x :  nums)
		std::cout << x<< "\n";
}

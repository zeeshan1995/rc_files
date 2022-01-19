

#include <iostream>
#include <vector>
#include <cmath>


const int MAX = 1e6+5;
int main()
{
	std::vector<bool>nums(MAX,true);

	nums[0] = nums[1] = false;
	int sq = sqrt(MAX);
	for(int i=2; i<=sq; i++)
	{
		if(!nums[i])
			continue;
		for(int j=2*i;j<=MAX; j+=i)
			nums[j] = false;
	}

	std::vector<int>sol;
	int p=0,ans=0;

	for(int i=0;i<=MAX;i++)
	{
		if(nums[i])
			p++;
		if(nums[p])
			sol.push_back(++ans);
		else
			sol.push_back(ans);
	}
/*
	for(int i=0; i<=20; i++)
		std::cout << i << " " << sol[i] << "\n";
		*/
	int t;
	std::cin >> t;

	while(t--)
	{
		int l,r;
		std::cin >> l >> r;


		std::cout << sol[r]-sol[l-1] << "\n";
/*		for(int i=l; i<=r; i++)
		{
			if(nums[i])
				p++;
			if(nums[p])
			{
			//	std::cout << p << " " <<i << "\n";;
				ans++;
			}
		}
*/
//		std::cout << ans << "\n";
	}
}

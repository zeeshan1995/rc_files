

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

std::vector<long long>dp;

int n;
std::vector<int>nums;
long long ans=LLONG_MIN;
void solve(int i,long long sum)
{
	if(i>=n)
	{
		if(sum&1 and sum>ans)
			ans=sum;
		return;
	}

	solve(i+1,sum+nums[i]);solve(i+1,sum);
}
int main()
{
	int t;
	std::cin >> t;

	while(t--)
	{
		std::cin >> n;

		nums.resize(n);
//		long long total=0;
		for(auto & x : nums)
		{
			std::cin >> x;
//			total+=x;
		}

	//	std::sort(nums.rbegin(), nums.rend());
	//
		
//		dp.resize(n,LLONG_MIN);
		
		ans=LLONG_MIN;
		solve(0,0);
/*		long long tmp=0,ans=LLONG_MIN;
		for(auto x : nums)
		{
			tmp+=x;
			if(tmp&1)
			{
				if(ans<tmp)
					break;
				ans = tmp;
			}
		}
		*/
		std::cout << ans << "\n";
	}
}

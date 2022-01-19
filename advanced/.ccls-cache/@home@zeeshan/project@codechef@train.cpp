


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct info
{
	int sad,lec;
};
int main()
{
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	std::cin >> t;

	while(t--)
	{
		int n,d;
		std::cin >> n >> d;

		std::vector<info>data;
		long long ans = 0;
		for(int i=0; i<n; i++)
		{
			int x,t,s;
			std::cin >> x >> t >> s;
			if(d- x +1 < t)
			{
				ans+= (t - d + x -1)*s;
				t = (d-x+1);
			}
			data.push_back({s,t});
		}

//		std::cout << ans <<"\n";
		std::sort(std::begin(data), std::end(data),[](info & a, info & b){return a.sad < b.sad;});

//		for(auto x : data)
//			std::cout << x.sad << "\n";
		for(auto i = data.size()-1; i>=0 and d>0; i--)
		{
			auto & x = data[i];
			auto m = std::min(x.lec, d);
		//	std::cout << i << " " << x.lec << " " << m << "\n";   
		/*	if(x.lec <= d)
			{
				ans += (x.lec * x.sad);
				d-=x.lec;
				x.lec = 0;
			}
			else
			{
			*/
				d-=m;
				x.lec-=m;
		//	}
		//	std::cout << x.lec << " " << d << "\n===\n";   
		}
//		for(auto x : data)
//			std::cout << x.lec << " ";

		for(auto x : data)
		{
			if(x.lec == 0 )
				break;
			ans += (x.lec * x.sad);
		}
		std::cout << ans << "\n";
	}
}

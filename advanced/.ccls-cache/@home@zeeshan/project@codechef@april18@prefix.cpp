

#include <iostream>
#include <string>
#include <vector>

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
		std::string s;
		int n;
		std::cin >> s >> n;

		std::vector<std::pair<int, int>>count;
		std::pair<int ,int> tmp{0,0};
		for(auto const &  x : s)
		{
			if(x == 'a')
				tmp.first++;
			else
				tmp.second++;
			count.push_back(tmp);
		}

		long long ans = 0, la = count.back().first, lb = count.back().second;
//		std::vector<std::vector<std::pair<int,int>>>xx(n);
//		int j=0;
		for(auto const & x : count)
		{
			int a = x.first, b = x.second;
			if(a > b)
				ans++;
			if(la > lb) 
			{
				if(la + a > lb + b)
				{
					ans+=n-1;
			//		std::cout << "[" << j << ":1-"<<n-1<<" "<<n-1<<"]\n"; 
				}
				else
				{
					/*
					int tmp = (b-a)/(la-lb);
					ans+= n - tmp ;
					if(la*tmp + a <= lb*tmp + b)
						ans--;
						*/
					int i=1, ta = la+a, tb = lb+b;
					while(ta <= tb and i<n)
					{
						ta+=la;
						tb+=lb;
						++i;
					}
					if(i<n)
					{
			//			std::cout << "[" << j <<": "<<i<< "-" << n-1 <<" "<<n-i<<"]\n";
						ans+=n-i;
					}
				}
			}
			else if( la < lb)
			{
				if( la + a > lb + b)
				{
					/*
					int tmp = (b-a)/(la - lb);
					ans+=tmp;
					if(la*tmp + a == lb*tmp + b)
						ans--;
						*/
					int i=1, ta = la+a, tb = lb+b;
					while(ta > tb and i<n)
					{
						ta+=la;
						tb+=lb;
						++i;
					}
					ans+=i-1;
				}
			}
			else
			{
				if(a > b)
					ans+=n-1;
			}
//			++j;
		}
		std::cout << ans << "\n";
	}
}

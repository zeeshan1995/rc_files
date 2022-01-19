


#include <iostream>
#include <vector>

int n,p;
std::vector<int>s;
std::vector<int>count;
int solve(int i, int p_t, int c)
{
	if(count[i]!=-1)
		return count[i];
	if(p_t >= p)
		count.insert(c);
	if(i >= n)
		return;
	solve(i+1, p_t+s[i], c+1);
	solve(i+1, p_t, c);
}
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
		std::cin >> n >> p;
		
		s.resize(n);

		for(auto & x : s)
			std::cin >> x;
		
		count.resize(n,-1);

		solve(n-1, 0, 0)
	}
}

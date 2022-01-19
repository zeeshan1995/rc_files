

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
int dig(int a)
{
	int s =0;
	while(a)
	{
		s+=a%10;
		a/=10;
	}
	return s;
}

std::set<int>m;
int ans = 1e9;
void solve(int a, int b)
{
	if(ans == 1)
		return;
	std::cout << a << " " << b << "\n";
	if(m.find(a) != m.end())
		return; 
	ans = std::min(ans, a);
	m.insert(a);
	solve(a+b, b);
	if(dig(a) != a)
		solve(dig(a), b);
}

int main()
{
	int a ,b;
	std::cin >> a >> b;
	solve(a,b);
	std::cout << ans << "\n";
}


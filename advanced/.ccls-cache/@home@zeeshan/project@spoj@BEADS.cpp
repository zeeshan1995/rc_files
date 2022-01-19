
//http://www.spoj.com/problems/BEADS/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string s;

bool comp(int a, int b)
{
	int i=a,j=b;

	std::string x="",y="";
	x+=s[i];y+=s[j];
	if(s[i] < s[j])
		return true;

	bool equal = s[i]==s[j];
	i=(i+1)%s.size();
	j=(j+1)%s.size();
	x+=s[i];y+=s[j];
	while(i!=a and s[i] <= s[j])
	{
		if(s[i]!=s[j])
			return true;
		i=(i+1)%s.size();
		j=(j+1)%s.size();
		x+=s[i];y+=s[j];
		if(s[i]!=s[j])
			equal = false;
	}
	std::cout << a <<" " << i <<" : " << x <<"\n" << b << " " << j <<" : "<< y <<"\n------\n";
	if(i==a)
	{
		if(equal)
			return a<b;
		return true;
	}
	return false;
}
int main()
{

	std::ios_base::sync_with_stdio(false);

	freopen("input.txt","r",stdin);
	int t;
	std::cin >> t;

	while(t--)
	{
		std::cin >> s;

		std::vector<int>v(s.size());
		std::iota(std::begin(v), std::end(v), 0);

		std::sort(v.begin(), v.end(),comp);

		for(auto x : v)
		{
			std::cout << x << ": ";
			std::cout << s[x];
			int i=x;
			for(++i; i!=x; i=(i+1)%s.size())
				std::cout << s[i] ;
			std::cout <<"\n";
		}
		std::cout <<"\n";
	}
}



//https://www.codechef.com/AUG17/problems/PALINGAM

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool solve(int c, std::string res,std::string a, std::string b)
{
	/*
	if(res.size()==0)
	{
		for(auto x : s[c])
		{
			if(!solve(1,res+x))
				return true;
		}
		return false;
	}
	*/
	std::vector<std::string> tmp;
	for(auto x : a)
	{
		for(int i=0; i<(int)res.size(); i++)
		{
			tmp.push_back(res);
			tmp.back().insert(i,1,x);
		}
		tmp.push_back(res);
		tmp.back().push_back(x);
	}
/*
	for(auto x : tmp)
		std::cout << x;
	std::cout <<"\n";
	return true;
*/
	if(res.size()>=1)
	{
		int l = (res.size()+2)/2;
		for(auto x : tmp)
		{
			bool pal = true;
			for(int i=0;i<l; i++)
			{
				if(x[i]!=x[res.size() - i])
				{
					pal = false;
					break;
				}
			}
			if(pal)
			{
				std::cout << "[ " << c << " " << x << "]\n";
				return true;
			}
		}
	}

	c++;
	if(c==2)
		c=0;
	for(auto x : tmp)
	{
		if(!solve(c,x))
			return true;
	}
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	std::cin >> t;

	while(t--)
	{
		std::string a, b;
		std::cin >> a >> b;

		if(solve(0, "",a ,b ))
			std::cout << "A\n";
		else
			std::cout << "B\n";
	}
}



#include <iostream>
#include <vector>
#include <algorithm>

bool predicate(std::pair<int, int>a, std::pair<int,int> b)
{
	if(a.first < b.first)
		return true;
	else if(a.first > b.first)
		return false;
	return a.second < b.second;
}
int main()
{
//	freopen("input.txt", "r", stdin);
	int m,x;
	std::cin >> m >> x;

	std::vector<std::pair<int, int> >eggs;

	int total=0;
	for(int i=0; i<m; i++)
	{
		int a;
		std::cin >> a;
		total+=a;
		std::pair<int,int>x(a,i);
		eggs.push_back(x);
	}

	std::sort(eggs.begin(), eggs.end(),predicate);
/*
	for(auto x : eggs)
		std::cout << x.first << " " << x.second << "\n";
		*/
	std::vector<std::pair<int, int> >sol(m);
	bool e = false;
	if(x>=total)
	{
		e = true;
		eggs[0].first--;
		total--;
		x = total;
	}

	int ans = x;
	for(int i=eggs.size(); i>=0; --i)
	{
		std::pair<int, int> z;
		if(x>= eggs[i].first)
		{
			z = std::make_pair(eggs[i].first,0);
			x-=eggs[i].first;
		}
		else
		{
			
			z = std::make_pair(x,eggs[i].first-x);
			x=0;
		}

		sol[eggs[i].second] = z;
		if(i==0 and e)
		{
			sol[eggs[i].second].second+=1;
		}
	}

	if(e)
		std::cout << "Sorry, we can only supply " << ans << " eggs\n";
	else
		std::cout << "Thank you, your order for " << ans << " eggs are accepted\n";
	for(int i=0; i<int(sol.size()); i++)
	{
		int a = sol[i].first, b = sol[i].second;
		std::cout << a+b << "\t" << a << "\t" << b << "\n";
	}
}

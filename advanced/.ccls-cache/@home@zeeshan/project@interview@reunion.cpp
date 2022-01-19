

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

struct compare
{
	bool operator()(int const & a, int const & b)
	{
		return a < b; 
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);

	freopen("input.txt","r",stdin);
	int n,k;
	std::string s;
	std::cin >>n >>k >> s;

	std::priority_queue<int,std::vector<int>,compare>q;

	std::vector<int>left(s.size(),0),right(s.size(),0);

	int y=-1;
	for(int i=0,j=s.size()-1,z=s.size();i<s.size(); i++,j--)
	{
		if(s[i]!='1')
		{
			left[i]=0;
			y++;
			if(i-y>0)
				q.push(i-y);
			y=i;
		}
		else
			left[i]=i-y;
		std::cout << i << " "<< s[i] << " " <<left[i] <<"\n";
		if(s[j]!='1')
		{
			right[j]=0;
			z=j;
		}
		else
			right[j]=z-j;
	}
	if(s.back()=='1')
	{
		y++;
		q.push({y,s.size()-1});
	}
/*
	while(!q.empty())
	{
		std::cout << q.top().first<<" " << q.top().second<<"\n";
		q.pop();
	}
	*/

	for(int i=0;i<k;i++)
	{
		int a;
		std::cin >> a;
		if(s[a]!='1')
		{
			if(a>0 and a<s.size()-1 and s[a-1]=='1' and s[a+1]=='1')
			{
				right[a-left[a-1]]=right[a+1];
				left[right[a+1]+a]=right[a-left[a-1]];
				q.push(right[a-left[a-1]]);
			}
			else(a>0 and s[a-1]='1')
			{
				left[a]=left[a]+1;
				right[a
			}
			if(a==0 and a<s.size()-1 and s[a+1]=='1')
			{
				right[a-left[a-1]]=right[a+1];
				left[right[a+1]+a]=right[a-left[a-1]];
				q.push(right[a-left[a-1]]);
			}
		}
	}
	std::cout << s <<"\n";
	for(auto x : left)
		std::cout <<x;
	std::cout <<"\n";
	for(auto x : right)
		std::cout <<x;
	std::cout <<"\n";
}

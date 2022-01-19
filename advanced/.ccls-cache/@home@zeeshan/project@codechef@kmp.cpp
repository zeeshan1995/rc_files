

#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::string pat,s;
	std::cin >> pat>>s;

	std::vector<int>pre(pat.size(),0);

	int l=0;
	for(int i=1; i<pat.size(); i++)
	{
		while(l>0 and pat[i]!=pat[l])
			l=pre[l-1];
		if(pat[i]==pat[l])
			l++;
		pre[i]=l;
	}

	for(int i=0,j=0;i<s.size(); i++)
	{
		if(pat[j]==s[i])
			j++;
		else if(j!=0)
			j=pre[j-1],--i;
		if(j==pat.size())
		{
			j=pre[j-1];
			std::cout << "found at "<<i-pat.size()+1 << "\n";
		}
	}
	for(int i=0; i<pat.size(); i++)
		std::cout << i << " ";
	std::cout <<"\n";
	for(int i=0; i<pat.size(); i++)
		std::cout << pat[i] << " ";
	std::cout <<"\n";
	for(int i=0; i<pat.size(); i++)
		std::cout << pre[i] << " ";
	std::cout <<"\n";
}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::vector<std::vector<int>>g(26);

//std::vector<std::string> ans;
//std::vector<std::string> ans;
std::set<std::string>ans;

void solve(int u, std::string s,int l,std::vector<bool>visited)
{
	std::cout << s.size()<< " ";
	visited[u] = true;
	if(l==26)
	{
		ans.insert(s);
		return;
	}

	for(int i=0; i<(int)g[u].size(); i++)
	{
		if(!visited[g[u][i]])
		{
			char c = 'A' + g[u][i];
	//		std::cout << c <<" ";
			std::string tmp = s;
			tmp.push_back(c);
			solve(g[u][i],tmp,l+1,visited);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	std::cin >> n;


	std::vector<bool>fir(26,true);

	while(n--)
	{
		std::string s;
		std::cin >> s;

		for(int i=1; i<(int)s.size(); i++)
		{
			g[s[i-1]-'A'].push_back(s[i]-'A');
			fir[s[i]-'A'] = false;
		}
	}
	/*
	char xx='A';
	for(auto x : g)
	{
		std::cout << xx << "--";
		for(auto y : x)
			std::cout << char(y + 'A') << " ";
		std::cout <<"\n";
		xx++;
	}
	*/
	std::vector<bool>visited(26,false);
	std::string s = "";
	for(int i=0; i<(int)fir.size(); i++)
	{
		if(fir[i])
		{
			char c = 'A' + i;
			std::cout << c << "\n";
			solve(i,s+c,1,visited);
			break;
		}
	}
//	std::sort(ans.begin(), ans.end());
	for(auto x : ans)
		std::cout << x << "\n";
}

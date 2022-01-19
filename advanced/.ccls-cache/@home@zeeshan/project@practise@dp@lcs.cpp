

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int lcsLength(int i, int j, std::string const & a, std::string const & b, std::vector<std::vector<int>> & length)
{
	if(i<0 or j<0)
		return 0;
	if(a[i]==b[j])
		length[i][j] = lcsLength(i-1, j-1, a, b, length) + 1;
	else
		length[i][j] = std::max(lcsLength(i-1, j, a, b, length), lcsLength(i, j-1, a, b, length));
	return length[i][j];
}

std::string lcs(std::string const & a, std::string const & b, std::vector<std::vector<int>> const & length)
{

	std::string s="";
	int i=a.size()-1, j = b.size()-1;
	while(i>=1 and j>=1)
	{
		if(a[i]==b[j])
		{
			s.insert(s.begin(),a[i]);
			--i;--j;
		}
		else if(length[i-1][j] < length[i][j-1])
			--i;
		else
			--j;
	}
	std::cout << s << "\n";
	return s;
}

std::string findLCS(std::string const & a, std::string const & b)
{
	std::vector<std::vector<int>>length(a.size(), std::vector<int>(b.size(),0));

	std::cout << lcsLength(a.size()-1, b.size()-1, a, b, length);

	return lcs(a, b, length);
	
}

int main()
{

	freopen("input.txt", "r", stdin);

	std::string a, b;
	std::cin >> a >> b;

	std::cout << a <<  " " << b << "\n";
	
	std::cout << findLCS(a, b) << "\n";
}

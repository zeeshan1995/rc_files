

#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::unordered_set<int>more;
	for(int i=0; i<n; ++i)
	{
		std::string s;
		std::cin >> s;

		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == '1')
				more.insert(i);
		}
	}
	if(more.size() > 1)
		std::cout << "B\n2\n";
	else
		std::cout << "A\n1\n";
}



#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n,m;
	std::cin >> n >> m;

	std::vector<int>a(n),b(m);

	std::vector<bool>both(9,false);
	for(auto & x : a)
		std::cin >> x;
	for(auto & x : b)
		std::cin >> x;

	std::sort(a.begin(),a.end());
	std::sort(b.begin(),b.end());

	bool found = false;
	for(int i=0; i<n and !found;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				std::cout << a[i] << "\n";
				found = true;
				break;
			}
		}
	}
	if(!found)
		std::cout << std::min(a[0],b[0])<<std::max(a[0],b[0])<< "\n";
}

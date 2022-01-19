

#include <iostream>
#include <vector>
#include <string>


int main()
{
	std::string p;
	std::cin >> p;

	int n;
	std::cin >> n;

	bool start = false,end = false;
	for(int i=0; i<n; i++)
	{
		std::string a;
		std::cin >> a;

		if(a==p)
			start = end = true;
		if(a[0]==p[0] or a[1]==p[0])
			start = true;
		if(a[1]==p[1] or a[0]==p[1])
			end = true;
	}

	if(start and end)
		std::cout <<"YES\n";
	else
		std::cout <<"NO\n";
}

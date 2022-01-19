

#include <iostream>
#include <vector>
#include <map>

int main()
{
	std::map<int,int>m;
	m[1]=2;
	m[2]=3;

	for(auto x : m)
		std::cout << x.begin() <<" ";
}

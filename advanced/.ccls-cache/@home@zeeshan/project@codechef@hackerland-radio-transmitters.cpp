

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int n, k;
	std::cin >> n>> k;

	std::vector<int>pos(n);

	for(auto & x : pos)
		std::cin >> x;

	std::sort(pos.begin(), pos.end());

//	for(auto x : pos)
//		std::cout << x << " ";
//	std::cout << "\n";
	int l=0,i=1,ans=0;;

	while(l<n)
	{
		while(i<n and pos[i]-pos[l]<=k and i++);
		ans++;l=i-1;
//		std::cout << pos[l] << " ";
		while(i<n and pos[i]-pos[l]<=k and i++);
		l=i;
//		std::cout << pos[l] <<"\n";
	}
	std::cout << ans << "\n";
}

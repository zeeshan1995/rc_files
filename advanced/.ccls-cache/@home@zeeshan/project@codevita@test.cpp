


#include <vector>
#include <algorithm>


int main()
{
	std::vector<std::pair<int,int>>x;
	std::sort(x.begin(), x.end());
	int z = x.back().first;
}



#include <iostream>
#include <vector>
#include <unordered_map>
template<class T>
long long cal(int v, T sum)
{
	int x=1,tmp = v;
	std::vector<int>place,digit;
	while(tmp>=10)
	{
		digit.push_back(tmp%10);
		place.push_back(digit.back()*x);
		tmp/=10;
		x*=10;
	}
	x*=tmp;
	long long ans = 0;
	if(!digit.empty())
		ans+=sum[x-1];
	else
		ans+=sum[x];

	for(auto y : place)
		ans+=y*tmp;
	if(!digit.empty())
		ans+=tmp;

	for(int i= (int) digit.size()-1; i>=0; i--)
	{
		ans+=sum[std::max(0, place[i]-1)];
		for(int j=i-1; j>=0; j--)
			ans+=(digit[i] * place[j]);
			ans+=digit[i];
	}

	return ans;

}
int main()
{
	std::ios_base::sync_with_stdio(false);

	int u,v;
	std::cin >> u >> v;

	while(u!=-1 and v!=-1)
	{
		int x=1,tmp = v;
		std::vector<int>place,digit;
		while(tmp>=10)
		{
			digit.push_back(tmp%10);
			place.push_back(digit.back()*x);
			tmp/=10;
			x*=10;
		}
		x*=tmp;

		std::unordered_map<int, long long>sum;
		sum[0] = 0;
		for(int i=1; i<=9; i++)
			sum[i] = sum[i-1]+i;

		int i=10,mul=10;

		
		while(i<x)
		{
			for(int j=2; j<=10 and i<x; j++)
			{
				i=j*mul;
				sum[i - 1] = sum[(j-1)*mul -1] + sum[mul-1] + (j-1)*mul;
			}
			mul*=10;
		}
		std::cout << cal(v,sum) - cal(std::max(0,u-1), sum) <<"\n";
		std::cin >> u >> v;
	}
}

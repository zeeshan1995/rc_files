

#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int>ans(n+1);
	ans[0]=1;
	int n2 = 2,n3=3,n5=5;

	int i2=0,i3=0,i5=0;
	for(int i=1;i<n;i++)
	{
		ans[i] = std::min(n2,std::min(n3,n5));
		std::cout << ans[i] << " ";
		if(ans[i]==n2)
		{
			i2++;
			n2=ans[i2]*2;
		}
		if(ans[i]==n3)
		{
			i3++;
			n3=ans[i3]*3;
		}
		if(ans[i]==n5)
		{
			i5++;
			n5=ans[i5]*5;
		}
	}
	std::cout << ans[n-1] <<"\n";
}

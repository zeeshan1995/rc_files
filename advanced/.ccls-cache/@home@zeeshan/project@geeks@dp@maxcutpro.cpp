

//http://www.geeksforgeeks.org/dynamic-programming-set-36-cut-a-rope-to-maximize-product/

#include <iostream>
#include <vector>

int main()
{
	int n=10;
	std::cin >> n;
	std::vector<int>ans(n+1,0);
	ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			/*
			if(ans[j]*ans[i-j]>ans[i])
				ans[i] = ans[j]*ans[i-j];
			if(j*ans[i-j]>ans[i])
				ans[i] = j*ans[i-j];
			if(ans[j]*(i-j)>ans[i])
				ans[i] = ans[j]*(i-j);
			if(j*(i-j)>ans[i])
				ans[i] = j*(i-j);
				*/
			ans[i] = std::max(ans[j],j) * std::max(ans[i-j],i-j);
		}
	}

	std::cout << ans[n]<< "\n";
}

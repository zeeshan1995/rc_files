

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
int main()
{
	int n;
	std::cin >> n;


	std::vector<double>vol;
	for(int i=0; i<n; i++)
	{
		double a;
		std::cin >>a;
		vol.push_back((4.0 * 3.14 * a * a * a)/3.0);
	}

	double p;
	std::cin >> p;
	std::sort(vol.begin(),vol.end());

	double ans = 0.0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1;j++)
			vol[i]-=((vol[i]*p)/100.0);
	//	std::cout << vol[i] << "\n";
		ans+=vol[i];
	}
//	std::cout << std::setprecision(2) << ans << "\n";
	long long x = ans*100;
	ans= (double)x/100;
	printf("%.2f\n",ans);
}

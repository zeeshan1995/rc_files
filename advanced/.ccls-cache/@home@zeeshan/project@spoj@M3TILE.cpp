

#include <iostream>
#include <vector>



int main()
{
		std::ios_base::sync_with_stdio(false);

		std::vector<int>sol(31,-1);

		sol[0]=1;
		sol[1]=0;
		sol[2]=3;
		sol[3]=0;

		for(int i=4; i<31; i++)
				sol[i] = 4*sol[i-2] - sol[i-4];

		int n;
		std::cin >> n;
		while(n!=-1)
		{
				std::cout << sol[n] << "\n";
				std::cin >> n;
		}
}

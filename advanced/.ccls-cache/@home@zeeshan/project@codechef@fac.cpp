

#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	unsigned long long a,b;
	std::cin >> a >> b;

	int ans=1;
	for(++a;a<=b and ans;a++)
		ans=(ans*(a%10))%10;

	std::cout << ans << "\n";
}

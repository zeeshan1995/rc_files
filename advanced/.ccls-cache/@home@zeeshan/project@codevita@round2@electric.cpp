

#include <iostream>
#include <string>


int main()
{
	int n;
	std::cin >> n;

	int ans = 0;

	for(int i=0; i<n; i++)
	{
		std::string s;
		std::cin >>s;

		int x = 0;
		for(int i=0; i<int(s.size()-1); i++)
		{
			if(s[i]=='J' and s[i+1] == 'A')
				x=x*10+0;
			else if (s[i] == 'I' and s[i+1] == 'B')
				x=x*10 +1 ;
			else if(s[i]=='H' and s[i+1]=='C')
				x=x*10+2;
			else if(s[i]=='G' and s[i+1]=='D')
				x=x*10+3;
			else if(s[i]=='F' and s[i+1]=='E')
				x=x*10+4;
			else
				x= x*10 + (s[i]-'A');
		}
		x= x*10 + (s[s.size()-1]-'A');
//		std::cout << x << "\n";
		ans+=x;
	}
	int f;
	std::cin >> f;
	if(ans > f)
		std::cout <<"GREEDY\n" << ans -f <<"\n";
	else
		std::cout << "INNOCENT\n";
}

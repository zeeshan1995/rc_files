

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	std::cin >> n;

	std::vector<int>count,index(1e6+5,-1);
	for(int i=0; i<n; ++i)
	{
		std::string s;
		std::cin >> s;

		for(int i = 0; i<s.size(); i++)
		{
			if(s[i] == '1')
			{
				if(index[i] == -1)
				{
					index[i] = count.size();
					count.push_back(0);
				}
				++count[index[i]];
			}
		}
	}
	int l = count.size(),move=1;
	while(true)
	{
		int x = 0, zero = -1;
		for(int i=0; i<l; ++i)
		{
		//	std::cout << x <<"] ";
			if(count[i] != 0)
				zero = i;
			x = count[i] xor x; 
		}
	//	std::cout << x <<"] ";
		if(zero == -1)
		{
			if(move & 1)
				std::cout << "B\n" << move - 1 << "\n";
			else
				std::cout << "A\n" << move - 1 << "\n";
			break;
		}
	//	for(int i=0; i<l; ++i)
	//		std::cout << count[i] << " ";
		if(x == 0)
			count[zero] = 0;
		else
		{
			for(int i=0; i<l; ++i)
			{
				if(count[i] xor x < count[i])
					count[i] = count[i] xor x;
				break;
			}
		}
		++move;
	//	for(int i=0; i<l; ++i)
	//		std::cout << count[i] << " ";
	//	std::cout << "\n";
	}
}

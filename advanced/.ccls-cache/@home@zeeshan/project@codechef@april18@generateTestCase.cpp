
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

unsigned long long seed()
{
	return static_cast<unsigned long long > (time(0));
}

int main(int argc, char ** argv)
{
	
	freopen("input.txt","w",stdout);

	std::default_random_engine e{seed()},d{seed()};

	std::uniform_int_distribution<int> genN(10,100),genData(-10,10);

	std::cout << 1 <<"\n"<<10<<"\n";
	int n =10;

	std::vector<int>nums;
	

	for(int i=0;i<n; i++)
	{
		
		std::cout<<genData(d)<< " ";
	}
}

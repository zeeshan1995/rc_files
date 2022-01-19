

#include <iostream>
#include <unistd.h>

int main(int argc, char ** argv)
{
	int t = atoi(argv[1]);
	for(int i=1; i<=t; i++)
	{
		std::cout << "Running test case number: " << i <<".....\n";
		system("./interval_map.out");
		std::cout << "--------------\n\n"; 
		sleep(1);
	}
}

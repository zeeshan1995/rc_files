

#include <iostream>

int* xx(int x)
{
	int y = 6;
	x= y;
	std::cout << (long long)&y << "\n";
	return &y;
}

int main()
{
	int z = 0;
	int * a = xx(26);
	std::cout << a << "\n";
}

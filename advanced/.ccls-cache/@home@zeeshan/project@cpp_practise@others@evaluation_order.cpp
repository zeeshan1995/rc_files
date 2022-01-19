

#include <iostream>

int count = 0;

int f1()
{
	return ++count;
}

int f2()
{
	count*=2;
	return count;
}

int f3()
{
	count*=3;
	return count;
}

int caller()
{
	return 1 + f1() + f2() + f3();
}

int main()
{
	std::cout << caller() << "\n";
}

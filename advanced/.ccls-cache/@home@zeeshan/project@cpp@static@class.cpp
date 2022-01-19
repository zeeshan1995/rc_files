

#include <iostream>

class A
{
	int a;

	public:
	A(int i=0){a=i;}
	~A(){exit(1);}
};

void y()
{
	static A z;
}
int main()
{
	A x;
	y();
	y();
	y();
	y();
}

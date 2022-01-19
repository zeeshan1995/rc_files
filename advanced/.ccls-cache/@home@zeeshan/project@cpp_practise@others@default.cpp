

#include <iostream>

class A
{
	public:
		explicit A(int i) {std::cout << "A constructed [" << i << "]\n";}
};

class B
{
	public:
		B(int i = 0) {std::cout << "B constructed [" << i << "]\n";}
};


void func(A a) {std::cout << "In func\n";}
void func(B a) {std::cout << "In func\n";}
int main()
{
	A a(23);
	func(a);
	func(15);

	B b;
	func()
}

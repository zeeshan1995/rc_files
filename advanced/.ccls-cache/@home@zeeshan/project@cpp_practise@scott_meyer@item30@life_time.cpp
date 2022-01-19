

#include <iostream>

class A
{
	int a;

	public:
	A() :a{23} {}
		void lamda()
		{
			auto print = [=]() { std::cout << a <<"\n"; };
			print();
		}
};

int main()
{
	int a =30, b=6;
	//auto test = [a](){a =10;}; // by value capture makes the captured value const
	auto test = [&a]() {a = 10;};
	test();
	std::cout << a << "\n";

	A x;
	x.lamda();
}


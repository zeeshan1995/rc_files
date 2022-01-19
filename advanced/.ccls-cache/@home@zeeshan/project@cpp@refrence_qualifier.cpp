

#include <iostream>

class Base
{

	public:
		//void hello() { std::cout << "Normal\n"; }
		void hello() & { std::cout << "lvalue\n"; }
		void hello() && { std::cout << "rvalue\n"; }
};
int main()
{
	Base b;
	b.hello();
	Base().hello();
}

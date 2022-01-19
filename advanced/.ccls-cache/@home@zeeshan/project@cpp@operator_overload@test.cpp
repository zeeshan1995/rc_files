

#include <iostream>

class Integer
{
	public:
	int a;

	Integer(int a):a(a){}

	Integer &operator+(const Integer & other) const
	{
		return other;
	}
};

int main()
{
	Integer a(5),b(10);
	std::cout << b.a << "\n";
	a = a + b;
	std::cout << a.a;
}

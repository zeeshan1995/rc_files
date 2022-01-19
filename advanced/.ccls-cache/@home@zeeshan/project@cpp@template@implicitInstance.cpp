

#include <iostream>

template <typename T>
class A
{
	T a;

	public:
	A() = default;
	A(const T & a) : a(a) {}

	T get() { return a;}
	T set(const T & a);
};


int main()
{
	A<int> a;
}

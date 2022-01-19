

#include <iostream>

template<typename T>
class A
{
	T a;

	public:
	A() = default;
	A(T const & a) : a(a){};
};


template<typename T, template<typename U> class A>
class B
{
	A<T> a;
	T b;

	public:
	B() = default;
	B(const T & b, const A<T> & a) : b(b), a(a) {}
};


int main()
{
	B<int,A<int>> b;
}

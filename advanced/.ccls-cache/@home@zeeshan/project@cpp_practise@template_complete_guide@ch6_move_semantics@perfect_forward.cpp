

#include <iostream>
#include <utility>


class x{};

void g(x&)
{
	std::cout << "g(x&)\n";
}

void g(const x&)
{
	std::cout << "g(const x &)\n";
}

void g(x&&)
{
	std::cout << "g(x&&)\n";
}
#if 0
void f(x& a)
{
	std::cout << "f(x&)\n";
	g(a);
}

void f(const x& a)
{
	std::cout << "f(const x &)\n";
	g(a);
}

void f(x&&a)
{
	std::cout << "f(x&&)\n";
	g(std::move(a));
}
#endif

template <typename T>
void f(T && x)
{
	g(std::forward<T>(x));
}

int main()
{
	x a;
	x const c;

	f(a);
	f(c);
	f(x{});
	f(std::move(a));
}



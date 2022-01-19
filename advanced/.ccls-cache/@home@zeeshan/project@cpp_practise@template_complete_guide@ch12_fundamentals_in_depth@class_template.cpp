

#include <iostream>
#include <vector>
template<typename T>
class Foo
{
	public:
#if 0
		template<typename U>
		Foo(U x) : a{T{}} {}
#else
		Foo() : a(T{}) {}
#endif
		template<typename>
		auto print()
			-> void
		{
			std::cout << a << "\n";
		}

	private:
		T a;
};

int C;
class C;
class C{};
#if 0
const char* C;
#endif

int main()
{
	Foo<int> x;
	x.print<int>();
	Foo<std::vector<int>> y;
#if 0
	y.print<int>()
#endif
}

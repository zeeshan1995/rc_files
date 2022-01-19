

#include <iostream>
#include <functional>

struct foo
{
	public:
		foo()
		{
			std::cout << "Default Ctor | Address[" << this << "]\n";	
		}

		foo(foo const & obj)
		{
			std::cout << "Copy Ctor | Address[" << this << "]\n";	
		}

		foo & operator = (foo const & obj)
		{
			std::cout << "Copy Assignment Operator | Address[" << this << "]\n";	
			return *this;
		}

		foo(foo && obj)
		{
			std::cout << "Move Ctor | Address[" << this << "]\n";	
		}

		foo & operator = (foo && obj)
		{
			std::cout << "Move Assignment Operator | Address[" << this << "]\n";	
			return *this;
		}

		~foo()
		{
			std::cout << "Dtor | Address[" << this << "]\n";	
		}
};

std::function<foo()> multiplier(foo const & n)
{
	std::cout << "Address of n in lambda creator=> [" << &n << "]\n";
	return [& n]()
	       { 
	           std::cout << "Address of n in lambda=> [" << &n << "]\n";
			   return n;
		   };
}

int main()
{
	std::cout << "Binding a function\n";
#if 0
	auto const x = foo{};

	auto const invocation = multiplier(x);
#else
	auto const invocation = multiplier(foo{});
#endif

	std::cout << "Calling the bound function\n";
	invocation();
}

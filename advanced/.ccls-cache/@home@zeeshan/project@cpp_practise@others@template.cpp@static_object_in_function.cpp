

#include <iostream>

template<typename T>
T add(T t)
{
	static auto x = 0;
	return (++x) + t;
}

auto plus(int a)
{
	static int b = 0;

	return [=](int c){ static int d = 0; return (d++) + (b++) + c + a;};
}


auto minus(int a)
{
	static int b = 0;
	return[](int c){ return b++;};
}

auto foo = [](auto t)
		   {
			   static int x = 0;
			   return (++x) + t;
		   };
int main()
{
	std::cout << add(1) << "\n";
	std::cout << add(3.14) << "\n";

	auto x1 = plus(20);
	auto x2 = plus(20);

	std::cout << x1(20) << "\n";
	std::cout << x2(20) << "\n";

	auto m1 = minus(10);
	auto m2 = minus(10);

	std::cout << "minus() --\n";
	std::cout << m1(10) << "\n";
	std::cout << m2(10) << "\n";
	std::cout << m1(10) << "\n";
	std::cout << m2(10) << "\n";

	std::cout << "foo \n";
	std::cout << foo(10) <<"\n";
	std::cout << foo(3.14) << "\n";
	std::cout << foo(10) <<"\n";
	std::cout << foo(3.14) << "\n";
	
}

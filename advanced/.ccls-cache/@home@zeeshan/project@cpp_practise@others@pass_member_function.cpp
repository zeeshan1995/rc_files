

#include <iostream>

struct foo
{
	void hello() { std::cout << "hello\n"; }
};

template <typename T>
void call(T x)
{
	x();
}
int main()
{
	foo x;
	x.hello();
	call([&x](){x.hello();});
}

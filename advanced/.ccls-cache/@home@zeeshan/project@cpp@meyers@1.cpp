
#include <iostream>

template <typename T>
void f(T & param) // void f(int & param) gives error for f(cx);
{
	param;
}

int main()
{
	int x = 27;
	int const cx = x;
	int const & rx = x;
	f(x);
	f(cx);
}

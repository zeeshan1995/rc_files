
#include <iostream>


constexpr int Increment(int n)	
{
	return [n] { return n + 1; }();
}

int main()
{
	constexpr int y = 32;
	auto answer = [y]() constexpr
	{
		int x = 10;
		return y + x;
	};
    constexpr int n = answer();
    static_assert(n==42);

    constexpr int p = Increment(23);
    static_assert(p==24);
}



#include <iostream>

template<int N>
struct fib
{
	static const int value = fib<N-1>::value + fib<N-2>::value;
};

template<>
struct fib<0>
{
	static const int value = 0;
};

template<>
struct fib<1>
{
	static const int value = 1;
};


int main()
{
	for(int i=0; i<11; i++)
		std::cout << fib<i>::value << "\n";
}

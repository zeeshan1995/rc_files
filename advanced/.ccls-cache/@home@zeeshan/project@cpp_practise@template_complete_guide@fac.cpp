

#include <iostream>

template<int N>
struct Factorial
{
    enum {value = N * Factorial<N-1>::value};
};
#if 0
template<>
struct Factorial<0>
{
    enum {value = 1};
};
#endif

int main()
{
    std::cout << Factorial<5>::value << "\n";
}

#include <iostream>

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}


constexpr int fib(int n)
{
    if( n < 0)
        throw std::invalid_argument("Argument must be greater than -1");
    if( n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n = factorial(10);
    std::cout << n << "\n";

    constexpr int a = fib(-1);
    std::cout << a << "\n";
}

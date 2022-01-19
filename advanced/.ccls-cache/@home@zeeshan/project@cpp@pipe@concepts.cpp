

#include <iostream>
#include <type_traits>

struct bar
{
    bar(int x) {}
};

#if 0
template <typename T>
requires std::is_default_constructible<T>::value
#else
template <typename T, typename _ = typename std::enable_if<std::is_default_constructible<T>::value>::type>
#endif
void foo(T const & x)
{
    T a{};
}



int main()
{
    bar x{1};
    foo(x);
}

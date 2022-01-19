#include <vector>
#include <algorithm>
#if 0
template <typename Datatype
         ,template<typename datatype> class Container>
   //      ,template<typename conatiner_iterator> class Callable>
void f(){}
//void f(Container<Datatype>){}
#endif

template<template <class, class> class H, class S, class X>
void f(H<S, X> const & name){}

template<typename T, typename... Args>
auto foo(T c, Args... a)
    ->decltype(foo(a...), int{})
{
    auto x  = "here\n";
}
template<>
void foo<>(){}
int main()
{
    //f<int,std::vector>();
    std::vector<int> name;
    f(name);
    //foo(std::sort, name, name, std::sort);
    foo(name, name);
}

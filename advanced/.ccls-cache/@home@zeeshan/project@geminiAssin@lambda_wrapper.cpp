

#include <iostream>
#include <unistd.h>

void print0()
{
	std::cout << "Zero Argument" << std::endl;
}

void print1(int const a)
{
	std::cout << "One Argument" << std::endl;
}

void print2(int const a, int const b)
{
	std::cout << "Two Argument" << std::endl;
}
template<typename Func>
void ping(Func && func)
{
	auto called = 0;
	while(called < 3)
	{
		std::cout << called <<": ";
		func();
		sleep(3);
		++called;
	}
}
#if 0
auto call_func = [](auto&& func, auto arg1){
	return func(arg1);};
auto call_ping = [](auto && func, auto arg1){
	return ping(func,arg1));};
#endif

#if 0
template<typename Func, typename Arg>
auto call_func(Func && func, Arg const arg1)
{
	return [func, arg1](){func(arg1);};
}
#endif
//auto call_ping(Func && func, Arg const arg1)
template<typename Func>
auto call_ping(Func * func)
{
	ping([func](){func();});
	//ping(call_func(func,arg1));
}

template<typename Func, typename Arg>
auto call_ping(Func * func, Arg const arg1)
{
	ping([func, arg1](){func(arg1);});
	//ping(call_func(func,arg1));
}

template<typename Func, typename Arg>
auto call_ping(Func * func, Arg const arg1, Arg const arg2)
{
	ping([func, arg1, arg2](){func(arg1,arg2);});
	//ping(call_func(func,arg1));
}

int main()
{
//	ping(print0);
//	ping([x=3](){print1(x);});
	call_ping(print1,3);
	call_ping(print0);
	call_ping(print2,1,2);
}

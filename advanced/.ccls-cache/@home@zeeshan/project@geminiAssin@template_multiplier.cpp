#include <iostream>
#include <functional>
#include <typeinfo>

//template <typename U, typename T>
//auto multiplier(T const & value) -> std::function<decltype(T*U)(U const &)> 
//auto multiplier(T const & value) -> std::function<decltype(T{} * U{})(U const &)> 
//auto multiplier(T const & value) 
//{
//	auto func = [value](U const x){
//		return value * x;
//	};
//	return func;
//}

template <typename T>
auto multiplier(T const & value) 
{
	auto func = [value](auto const & x){
		return value*x;
	};
	return func;
}

int main()
{
	//auto twice = multiplier<double>(2);
	auto twice = multiplier(2);
	std::cout << "twice(5) -> " << twice(5) << std::endl;
	std::cout << "twice(10.5) -> " << twice(10.5) << std::endl;

	return 0;
}


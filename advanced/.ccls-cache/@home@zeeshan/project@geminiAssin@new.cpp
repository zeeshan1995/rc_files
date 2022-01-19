
/*
 * auto twice = multiplier(2);
 * std::cout << twice(3) << "\n";  
*/

#include <iostream>
#include <functional>



template<typename T, typename U>
auto multiplier(T const & n) -> std::function<decltype(T*U)(U const &)>
{
//	template<typename T>//typename P>
	return [n](U const & x){ return n*x;};
}

int main()
{
	auto twice = multiplier<int,double>(2);
	std::cout << twice(10.5) <<"\n";
}

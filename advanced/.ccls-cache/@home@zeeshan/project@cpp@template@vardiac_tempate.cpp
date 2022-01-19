

#include <iostream>

template<typename T>
bool pair_comp(T a)
{
	return false;
}

template<typename T>
bool pair_comp(T a, T b)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return a==b;
}

template <typename T, typename... Args>
bool pair_comp(T a, T b, Args... args)
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	return a==b and pair_comp(args...);
}
int main()
{
	std::cout << pair_comp(1,2,3,5,7,9,10,3,17) << "\n";
}

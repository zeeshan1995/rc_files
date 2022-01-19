

#include <iostream>
#include <string>

template<typename T, unsigned N>
std::size_t len( T(&) [N])
{
	return N;
}

template<typename T>
std::size_t len(T const & t)
{
	return t.size();
}


int main()
{
	int nums_a[25];

	std::cout << len(nums_a) << "\n";
	std::cout << len("zee") << "\n";
	std::cout << len(std::string{"zee"}) << "\n";
}

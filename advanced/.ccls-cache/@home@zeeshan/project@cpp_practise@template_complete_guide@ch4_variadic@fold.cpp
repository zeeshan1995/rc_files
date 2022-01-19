

#include <iostream>

template <typename... types>
auto foldsum (types... s)
{
	return (... + s); 
}

int main()
{
	std::cout << foldsum(1,2,3,4,5) << "\n";
}

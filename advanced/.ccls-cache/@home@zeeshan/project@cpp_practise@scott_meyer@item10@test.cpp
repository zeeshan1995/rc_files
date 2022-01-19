

#include <iostream>
#include <vector>

enum color
{
	black,
	white,
	red
};
template<typename T>
int std::vector<T>::size() const
{
	std::cout << "hell\n";
	return 1;
}
int main()
{
	auto white = false;

	std::vector<int> nums = {1,2,3};
	std::cout << nums.size() << "\n";
}

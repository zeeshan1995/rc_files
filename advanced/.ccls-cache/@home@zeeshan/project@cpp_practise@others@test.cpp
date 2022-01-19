



#include <iostream>
#include <vector>
template<typename T,
	typename Result = decltype(
			std::declval<std::ostream&>() << std::declval<T const&>()
			),
	typename std::enable_if<
	!std::is_convertible<Result, std::ostream&>::value,
	int
	>::type = 0>
void say(T x)
{
	std::cout << "say" << "\n";
}


int main()
{
#if 0
	say("name");
#else
	std::vector<int>nums = {1,2};
	say(nums);
#endif
}


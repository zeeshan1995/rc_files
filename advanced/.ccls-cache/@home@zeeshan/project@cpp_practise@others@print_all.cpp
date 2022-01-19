

#include <iostream>
#include <vector>
#include <type_traits>
//template<typename T>
//auto print(T input) -> decltype( std::cout << input ,void());

//template<typename Input,typename std::enable_if<
//						false == std::is_convertible<decltype(std::declval<std::ostream&>() << std::declval<Input const &>()), std::ostream&>::value, int>::type =1>
//auto print(Input input) -> decltype(!std::is_convertible<decltype(std::declval<std::ostream&>() << std::declval<Input const &>()), std::ostream&>::value, input.begin(), void())

template <typename Input, int =1>
auto print(Input input) -> decltype(input.begin(), void())
{
	std::cout << std::is_convertible<decltype(std::cout << std::declval<Input const &>()), std::ostream&>::value << "\n";
	for(auto const & x  : input)
		std::cout << x << " ";
}

template<typename Input , int = 1>
auto print(Input input) -> decltype( std::cout << input ,void())
{
	std::cout << std::is_convertible<decltype(std::cout << std::declval<Input const &>()), std::ostream&>::value << "\n";
	std::cout << input << "\n";
}

int main()
{
#if 1
	std::vector<int> nums ={1,2,3,4,5,6};
	print(nums);
#endif
	int x = 12345;
	print(x);

//	std::vector<std::vector<int>> mat = {{10,20,30},{40,50,60}};
//	print(mat);
//	std::string abc = "hello";
//	print(abc);
}

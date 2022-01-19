#include <iostream>
#include <type_traits>

// Every problem can be solved => Adding one more layer
// SFINAE => Substitution Failure Is Not An Error
template <typename LHS, typename RHS>
auto multiply(LHS const & lhs, RHS const & rhs) -> decltype(lhs * rhs)
{
	return lhs * rhs;
}

template <typename LHS>
auto multiply(LHS const & lhs, std::string const & rhs) -> std::string
{
	static_assert(std::is_integral<LHS>::value,"Invalid");
	
	std::string result{};
	for (auto start = 0; start < lhs; ++start)
	{
		result += rhs;
	}
	return result;
}

template <typename RHS>
auto multiply(std::string const & lhs, RHS const & rhs) 
			-> decltype(multiply(rhs, lhs))
{
	return multiply(rhs, lhs);
}

template <typename Real>
auto multiplier(Real const & factor) 
{
	auto func = [factor](auto const & x){
		return multiply(factor, x);
		//return value*x;
	};
	return func;
}

int main()
{
	//auto twice = multiplier<double>(2);
	auto twice = multiplier(2);
	auto two_point_five = multiplier(2.5);
	auto abc = multiplier("abc");

	std::cout << "twice(5) -> " << twice(5) << std::endl;
	std::cout << "twice(10.67) -> " << twice(10.67) << std::endl;
	std::cout << "twice(hello) -> " << twice("hello") << std::endl;

	std::cout << "two_point_five(5) -> " << two_point_five(5) << std::endl;
	std::cout << "two_point_five(10.67) -> " << two_point_five(10.67) << std::endl;
	std::cout << "two_point_five(hello) -> " << two_point_five("hello") << std::endl; // Restrict this

	std::cout << "abc(3) -> " << abc(3) << std::endl;
	std::cout << "abc(3.7) -> " << abc(3.7) << std::endl;

	return 0;
}


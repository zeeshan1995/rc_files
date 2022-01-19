


#include <util.hpp>

#include <string>

namespace util
{
	int add(int const a, int const b)
	{
		return a+b;
	}

	std::string hello(std::string const & a)
	{
		return "hello " + a;
	}
}



#include <cutil.h>
#include <util.hpp>
#include <iostream>

int add(int const a, int const  b)
{
	return util::add(a, b);
}

const char * hello(char const * a)
{
	return util::hello(a).c_str();
}


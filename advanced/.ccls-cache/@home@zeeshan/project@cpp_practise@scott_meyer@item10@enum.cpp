

#include <iostream>

#define NAMESPACE
//#undef NAMESPACE

#ifdef NAMESPACE
namespace test
{
#endif
	enum Color
	{
		black, 
		white,
		red
	};
#ifdef NAMESPACE
}
#endif

auto white = "white";

int main()
{

#ifdef NAMESPACE
	std::cout <<"With namespace\n";
	test::Color c = test::Color::red;
	test::Color w = test::Color::white;
#else
	std::cout << "Without namespace\n";
	Color c = red;
#endif
	std::cout <<c <<"\n";
}

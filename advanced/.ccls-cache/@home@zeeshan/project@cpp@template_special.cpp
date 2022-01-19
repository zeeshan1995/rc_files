

#include <iostream>
#include <string>


template <typename T>

class DoublePlay
{
	T mine;
	public:
	DoublePlay(T const & a):mine(a) {};
	T doubleIt(){ return 2.0*mine; }
};

template<>
class DoublePlay<std::string>
{
	std::string mine;
	public:
	DoublePlay(std::string const & a):mine(a) {};
	std::string doubleIt(){ return mine.append(mine); }
	void newFunction(){std::cout << "new\n";}
};

int main()
{
	DoublePlay<int> dint(25);
	std::cout << dint.doubleIt() << "\n";
	DoublePlay<float> fint(25.0);
	std::cout << fint.doubleIt() << "\n";


	DoublePlay<std::string> sint("zeeshan ");
	std::cout << sint.doubleIt() << "\n";
	sint.newFunction();
}

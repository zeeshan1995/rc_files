


#include <iostream>
#include <functional>

#if 0
class multiplier
{
	int _times;

	public:
		multiplier(int times) : _times(times) {}

		int operator()(const int n) 
		{
			return _times*n;
		}
};
#else
std::function<int(int const)> multiplier(int const n)
{
	return [n](int const x){ return n*x;};
}
#endif
int main()
{
	auto x = multiplier(45);
	std::cout << x(10) << "\n";
}

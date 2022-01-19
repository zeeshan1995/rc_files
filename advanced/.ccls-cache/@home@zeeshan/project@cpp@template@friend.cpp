

#include <iostream>
#include <initializer_list>
#include <vector>

template<typename T>
class Array;

template<typename T>
int size(Array<T> const & A);

template<typename T>
class Array
{
	std::vector<T> * array;

	public:
	Array() : array(new std::vector<T>){};
	void push(const T & elem)
	{
		array->push_back(elem);
	}

	T & operator[](int i)
	{
		return array[i];
	}

	friend int size<T>(const Array<T> & A);
};

template<typename T>
int size(const Array<T> & A)
{
	std::cout << "generic ";
	return A.array->size();
}

template<> int size(const Array<int> & A)
{
	std::cout << "Int ";
	return A.array->size();
}
template <typename T>
class Derived : public Array<T>
{
	public:
		int n;
};

template <typename T>
void swap(const T & a, const T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}
int main()
{

	Array<int> nums;
	std::cout<< size(nums) << "\n";
	Array<float> numsf;
	std::cout<< size(numsf) << "\n";
	Derived<int> x;
	std::cout << size(x) << "\n";
	swap(nums, x);
}

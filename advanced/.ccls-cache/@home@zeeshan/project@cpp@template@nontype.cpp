

#include <iostream>
#include <type_traits>

template<long long N>
struct Factorial
{
	static const long long value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0>
{
	static const long long value = 1;
};


template<typename T, int N>
struct add_pointer
{
	using type = typename add_pointer<T, N-1>::type*;
};

template<typename T>
struct add_pointer<T, 0>
{
	using type = T;
};

template<typename ... Ts>
struct typelist {};


template<typename TL, typename T>
struct push_back;

template<typename ... Ts, typename T>
struct push_back<typelist<Ts...>, T>
{
	using type = typelist<Ts..., T>;
};

int main()
{
	using mytypes = typelist<int, char>;
	using more_types = push_back<mytypes, long>::type;
	
	static_assert(std::is_same<more_types, typelist<int, char, long>>::value, "not same");

	//add_pointer<int, 3>::type x = "100";
	std::cout << Factorial<10>::value << "\n";
}


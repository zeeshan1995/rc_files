

#include <iostream>

#include "../../utils/type_name.hpp"

#define gen_func(f,ref) template<typename T> \
	void f(T ref param)\
	{\
		std::cout << "In " << __func__ <<" : param => [" <<type_name<decltype(param)>() << "] T => [" << type_name<T>() << "]\n";\
	}\

gen_func(ref,&)
gen_func(universal_ref,&&)
gen_func(pass_value, )

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

int main()
{
	int n = 25;
	int & reff = n;
	int const & const_ref = n;
	std::cout << "Object defination done\n";

	ref(n);
	ref(reff);
	ref(const_ref);

	universal_ref(n);
	universal_ref(reff);
	universal_ref(const_ref);
	universal_ref(std::move(n));
	universal_ref(std::move(reff));
	universal_ref(std::move(const_ref));

	pass_value(n);
	pass_value(reff);
	pass_value(const_ref);

	const char ptr[] ="Zeeshan";

	ref(ptr);

	std::cout << arraySize(ptr) << "\n";
}

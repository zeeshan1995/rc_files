

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <type_traits>


template<typename Input>
auto print(Input input) -> decltype( std::cout << input, void());

template<typename Input>
auto print(Input input) -> decltype(input.begin(), void());

template<typename Input>
auto print(Input input) -> decltype(print(input.first), void());

template<typename Input>
auto print(Input input) -> decltype( std::cout << input, void())
{
	std::cout << input;
}

template<typename Input>
auto print(Input input) -> decltype(input.begin(), void())
{
	for(auto const & x  : input)
	{
		print("{");
		print(x);
		print("},");
	}
}

template<typename Input>
auto print(Input input) -> decltype(print(input.first), void())
{
	print("[");
	print(input.first);
	print(":");
	print(input.second);
	print("]");
}

template<typename Input>
auto println(Input input) -> decltype(print(input), void())
{
	print(input);
	std::cout << std::endl;
}
#if 0
template<typename std::enable_if<is_container<T>::value>::type>
void test(T t)
{
	;
}
#endif
int main()
{
	println(1);   // int 
	println(1.4); // double
	println('c'); // char

	println("const char *"); // const char *   "abc"      array<char> = {'a', 'b', 'c' }
//	println(std::string{"string"}); // std::string
	
	std::set <int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	println(s);
	
	std::vector <int> vec;
	std::vector <std::set<int> > vs {s, s};
	println(vs);
	
	vec.push_back(5); vec.push_back(6); vec.push_back(7);
	println(vec);
	
	auto p = std::make_pair(5, 25);
	println(p);
	
	std::map<int, std::vector<int> > m;
	m.insert(std::make_pair(1, std::vector<int>{97, 76, 87}));
	m.insert(std::make_pair(2, std::vector<int>{98, 77, 88}));
	
	println(m);

}

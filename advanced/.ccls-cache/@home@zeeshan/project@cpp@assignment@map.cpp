

#include <iostream>
#include <map>
#include <limits>

template <typename K, typename V>
void print(std::map<K, V> const & m)
{
	for(auto x : m)
		std::cout <<x.first << " " << x.second << "\n";
}

int main()
{
	std::map<unsigned int,char>m;
    m.insert(m.begin(),std::make_pair(std::numeric_limits<unsigned int>::lowest(),'A'));
    m.insert(m.begin(),std::make_pair(20,'B'));
	print(m);
	auto notLess = m.lower_bound(20),greater = m.upper_bound(20);
	if(!notLess->second)
		std::cout << "Absent\n";
	std::cout << notLess->first<<" " << notLess->second << "\n";
	std::cout << greater->first<<" " << greater->second << "\n";
}

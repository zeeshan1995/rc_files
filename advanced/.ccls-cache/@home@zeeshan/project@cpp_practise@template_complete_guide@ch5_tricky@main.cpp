

#include "stack.hpp"

#include <iostream>

int main()
{
	zee::stack<int> s;
	s.push(1);
	s.push(2);
	std::cout << s.top() << "\n";
	s.pop();
	std::cout << s.empty() <<"\n";
	s.push(3);
	s.push(4);
	s.push(5);
	std::cout << s << "\n";

	zee::stack<std::pair<int,int>> p;

	p.push({1,1});
#if 0
	p.print(); // Commenting this doesn't give compilation error inspite of the fact that it cant print std::pair, this is because is a class temple member function is instantiated only if it is used
#endif

//	std::vector cpp17{1,2,3}; // This works only after c++17

	zee::stack<float> f;
	f.push(1.1);
	f.push(1.2);
	f.push(1.3);
	f.push(1.4);
	f.push(1.3);
	f.push(2.1);
	f.push(2.2);

	std::cout << f << "\n";
	f = s;
	std::cout << s << "\n";
}

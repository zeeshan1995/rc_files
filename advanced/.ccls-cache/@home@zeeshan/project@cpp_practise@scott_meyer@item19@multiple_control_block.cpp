

#include <memory>
#include <vector>
#include <iostream>


int main()
{
	int * n = new int(24);
	std::cout << n << "\n";

	std::shared_ptr<int> sp1= std::make_shared<int>(n,[](int * n)
													{
														std::cout <<"Inside deleter\n";
														std::cout << "Add => [ " << n << "]\n";
														std::cout << "Val => [ " << *n << "]\n";
														delete n;
													});
}

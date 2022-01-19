

#include <iostream>
#include <memory>
#include <string>

int main()
{
	std::string name = "zeeshan";
	
	std::shared_ptr<std::string> p,q,r;
	std::unique_ptr<std::string> a,b,c;

	a=std::make_shared<std::string>name;
}

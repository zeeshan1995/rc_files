

#include <iostream>
#include <memory>

class Person
{
	std::string name;
	int height;

	public:
	Person()=default;
	Person(std::string const & name, const int & height) : name(name), height(height) {}

	std::string getName()
	{
		return name;
	}
};
int main()
{
	auto sp = std::make_shared<Person>(Person(std::string("zeeshan"),5));
	std::cout << sp->getName() << "\n";

#if 0
	int a = 10;
	{
	std::shared_ptr<int> p = std::make_shared<int>(a);
	std::cout << p.use_count() <<"\n";

	auto q(p);
	std::cout << p.use_count() <<"\n";
	std::cout << q.use_count()<<"\n";
	}
	//std::cout << p.get() <<"\n";
	std::cout << a<<"\n";
#endif
}

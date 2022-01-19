

#include "observer.hpp"

#include <iostream>
#if 1
class user : public observer
{
	public:
		user(std::string name) :_name{std::move(name)} {}
		void update()
		{
			std::cout << _name << " update\n";
		}

	private:
		std::string _name;
};

class stock : public observable
{
	public:
		stock(int price) : _price{price} {}
		void update_price(int new_price){ _price = new_price; notify();}
	private:
		int _price;
};
#endif
int main()
{
	auto s1 = std::make_shared<stock>(123);
#if 1
	auto A = std::make_shared<user>("A");
	{
	auto B = std::make_shared<user>("B");
	s1->add_observer(A);
	s1->add_observer(B);
	s1->update_price(50);
	}
	std::cout << "B is destroyed\n";
	s1->update_price(10);
	s1->update_price(10);
#endif
}

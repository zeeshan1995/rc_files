

#include "observer.hpp"

#include <iostream>

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

int main()
{
	stock s1{123};
	user A{"A"};
	{
	user B{"B"};
	s1.add_observer(A);
	s1.add_observer(B);
	s1.update_price(50);
	}
	std::cout << "B is destroyed\n";
	s1.update_price(10);
}

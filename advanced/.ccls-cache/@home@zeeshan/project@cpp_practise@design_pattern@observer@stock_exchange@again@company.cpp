

#include "observer.hpp"

#include <string>
#include <iostream>

class country : public observable 
{
	std::string _name;

	public:
		country(std::string name) : _name{std::move(name)} {}
};

class stock_exchange : public observer
{
	public:

		stock_exchange(std::string name, country & c) : _name{std::move(name)}, _country(&c) {}
		void update()
		{
			std::cout << "stock_exchange: [" <<_name << "] update.\n";
			_country->notify();
		}
	private:
		std::string _name;
		country * _country;
};

class stock : public observable
{
	public:
		stock(std::string name, int price) : _name{std::move(name)}, _price{price} {}
		void update_price(int new_price)
		{ 
			std::cout << "stock["<< _name <<"] updated.\n";
			_price = new_price; 
			notify();
		}

		void list_on(stock_exchange & s) { this->add_observer(s); };
	private:
		std::string _name;
		int _price;
};



class user : public observer
{
	public:

		user(std::string name) :_name{std::move(name)} {}
		void update()
		{
			std::cout << "user: ["<<_name << "] update\n";
		}

		void interseted(country & c)
		{
			c.add_observer(*(this));
		}
	private:
		std::string _name;
};

int main()
{
	std::cout << "hello stock!\n";

	country india("India");

	stock_exchange bse("bse", india);
	stock_exchange nse("nse", india);

	stock tcs("tcs",1234);
	tcs.list_on(bse);

	stock tata("tata",1234);
	tata.list_on(nse);

	std::cout <<"start\n";
	//tcs.update_price(30);
	{
		user a1("a1");
		a1.interseted(india);
		tata.update_price(40);
		std::cout << "a1 end\n";
	}

	user a2("a2");
	a2.interseted(india);
	tcs.update_price(30);
	tcs.update_price(20);


	user a3("a3");
	user a4("a4");
	user a5("a5");
	user a6("a6");
	user a7("a7");
}

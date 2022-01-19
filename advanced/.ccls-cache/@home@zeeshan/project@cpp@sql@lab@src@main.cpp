

#include <iostream>

#include "interact.hpp"
#include "sqlexception.hpp"
#include "utility.hpp"
int main()
{
	try
	{
		std::string config="/home/zeeshan/project/geminiAssin/sql/config/connection.config.json";
		interact::interact(config);
	}
	catch(sqlexception::SQLException const & e)
	{
		std::cout << utils::errorHandler(e) << "\n";
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << "\n";
	}
}

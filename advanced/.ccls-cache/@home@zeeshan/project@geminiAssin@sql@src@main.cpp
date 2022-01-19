

#include <iostream>

#include "interact.hpp"
#include "sqlexception.hpp"
#include "utility.hpp"
int main()
{
	int ret_code=1;
	try
	{
		std::string config="/home/zeeshan/project/geminiAssin/sql/dist/config/connection.config.json";
		interact::interact(config);
		ret_code=0;
	}
	catch(sqlexception::SQLException const & e)
	{
		utils::errorHandler(e);
	}
	catch(std::exception const & e)
	{
		utils::errorHandler(e);
	}
	catch(...)
	{
		utils::errorHandler(std::current_exception());
	}
	return ret_code;
}

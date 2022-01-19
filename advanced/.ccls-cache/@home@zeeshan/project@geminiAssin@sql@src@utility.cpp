
// Pre-defined header file.

#include <iostream>


// Self-defined header file.

#include "sqlexception.hpp"
#include "utility.hpp"


namespace utils
{

	std::string takeInput(std::string const dial,std::string const & def)
	{
		std::string s;
		std::cout << dial;
		std::getline(std::cin, s);
		return s.empty() ? def: s;
	}


	void errorHandler(sqlexception::SQLException const & e)
	{
		std::cout << std::string("\033[31m# ERR: ")  << e.what() << ", SQLState: " << e.getSQLState() << " )\033[0m";
	}
	void errorHandler(std::exception const & e)
	{
		std::cout << std::string("\033[31m# ERR: ")  << e.what() <<"\n"; 
	}

	void errorHandler(std::exception_ptr const & eptr)
	{
		try
		{
			std::rethrow_exception(eptr);
		}
		catch(std::exception const & e)
		{
			std::cout << e.what() << "\n";
		}
	}

	std::string appendWhere(std::string const & s, std::string const & where)
	{
		return where.empty() ? s +";" : s + " where " + where +";";
	}
}

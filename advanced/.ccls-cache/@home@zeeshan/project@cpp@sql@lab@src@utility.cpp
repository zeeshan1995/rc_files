
// Pre-defined header file.

#include <iostream>


// Self-defined header file.

#include "sqlexception.hpp"
#include "utility.hpp"


namespace utils
{

	// Doubt
	std::string takeInput(std::string const dial,std::string const & def)
	{
		std::string s;
		std::cout << dial;
		std::getline(std::cin, s);
		return s.empty() ? def: s;
	}


	std::string errorHandler(const sqlexception::SQLException & e)
	{
		return std::string("\033[31m# ERR: ") + e.what() + ", SQLState: " + e.getSQLState() + " )\033[0m";
	}

	std::string appendWhere(std::string const & s, std::string const & where)
	{
		return where.empty() ? s +";" : s + " where " + where +";";
	}
}

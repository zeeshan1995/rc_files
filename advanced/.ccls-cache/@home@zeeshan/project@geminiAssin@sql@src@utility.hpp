#pragma once

// Pre-defined header files.

#include <string>

// self-defined header files.

#include "sqlexception.hpp"


namespace utils
{
	std::string takeInput(std::string const dial, std::string const & def="");


	void errorHandler(sqlexception::SQLException const & e);
	void errorHandler(std::exception const & e);
	void errorHandler(std::exception_ptr const & e);

	std::string appendWhere(std::string const & s, std::string const & where);

}

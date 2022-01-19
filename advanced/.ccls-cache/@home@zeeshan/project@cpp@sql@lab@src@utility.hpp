#pragma once

// Pre-defined header files.

#include <string>

// self-defined header files.

#include "sqlexception.hpp"


namespace utils
{
	std::string takeInput(std::string const dial, std::string const & def="");


	std::string errorHandler(const sqlexception::SQLException & e);

	std::string appendWhere(std::string const & s, std::string const & where);

}

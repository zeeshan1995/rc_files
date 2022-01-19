#pragma once

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>


#include "driver.hpp"

namespace utils
{
	std::string takeInput(std::string const dial, std::string const & def="");

	int globalMenu();

	std::pair<std::string, std::string> extractColValues(std::string data);
	std::string errorHandler(driver::SQLException & e);

	std::string appendWhere(std::string const & s, std::string const & where);


	void interact(driver::Connection & con);
}

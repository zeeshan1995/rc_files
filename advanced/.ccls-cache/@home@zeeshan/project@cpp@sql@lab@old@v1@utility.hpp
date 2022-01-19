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


#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


class manipulationResult
{
	bool status;
	std::string msg;

	public:
	manipulationResult();
	manipulationResult(bool status, std::string const & msg);

	bool getStatus();
	std::string getMsg();
};

void printQueryResult(sql::ResultSet * r);

std::string takeInput(std::string const dial, std::string const & def="");

int globalMenu();

std::pair<std::string, std::string> extractColValues(std::string data);
std::string errorHandler(sql::SQLException & e);

std::string appendWhere(std::string const & s, std::string const & where);

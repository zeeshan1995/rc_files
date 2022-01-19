

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

#include "utility.hpp"

manipulationResult::manipulationResult() = default;
manipulationResult::manipulationResult(bool status, std::string const & msg) : status(status), msg(msg) {}

bool manipulationResult::getStatus() { return status; }
std::string manipulationResult::getMsg() { return msg; }


void printQueryResult(sql::ResultSet * r)
{
	auto meta = r->getMetaData();
	auto cols = meta->getColumnCount();
	for(int i=1; i<=int(cols); i++)
		std::cout << meta->getColumnName(i) <<"\t\t";
	std::cout << "\n";

	while(r->next())
	{
		for(int i=1; i<=int(cols); i++)
			std::cout << r->getString(i)<<"\t\t";
		std::cout << "\n";
	}
	std::cout << "\n==========\n";

}
// Doubt
std::string takeInput(std::string const dial,std::string const & def)
{
	std::string s;
	std::cout << dial;
	std::getline(std::cin, s);
	return s.empty() ? def: s;
}
int globalMenu()
{
	std::cout << "Select operation:\n" <<
		"1.Select\n2.Insert\n3.Update\n4.Delete\n5.Quit\n";
	int choice;
	std::cin >> choice;
	std::cin.ignore();
	return choice;
}

std::pair<std::string, std::string> extractColValues(std::string data)
{
	std::stringstream ss(data);
	std::string colnames, values;
	while(!ss.eof())
	{
		std::string s;
		ss >> s;
		auto it = std::find(s.begin(), s.end(),'=');
		if(!colnames.empty())
		{
			colnames+=",";
			values+=",";
		}
		colnames+=s.substr(0, it- s.begin());
		values+=s.substr(it- s.begin()+1,s.size());
	}
	return {colnames, values};
}


std::string errorHandler(sql::SQLException & e)
{
	return std::string("\033[31m# ERR: ") + e.what() + ", SQLState: " + e.getSQLState() + " )\033[0m";
}

std::string appendWhere(std::string const & s, std::string const & where)
{
	return where.empty() ? s +";" : s + " where " + where +";";
}

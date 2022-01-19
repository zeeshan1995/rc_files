

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
#include "db_operations.hpp"
#include "utility.hpp"




// Doubt
std::string utils::takeInput(std::string const dial,std::string const & def)
{
	std::string s;
	std::cout << dial;
	std::getline(std::cin, s);
	return s.empty() ? def: s;
}
int utils::globalMenu()
{
	std::cout << "Select operation:\n" <<
		"1.Select\n2.Insert\n3.Update\n4.Delete\n5.Quit\n";
	int choice;
	std::cin >> choice;
	std::cin.ignore();
	return choice;
}


std::string utils::errorHandler(driver::SQLException & e)
{
	return std::string("\033[31m# ERR: ") + e.what() + ", SQLState: " + e.getSQLState() + " )\033[0m";
}

std::string utils::appendWhere(std::string const & s, std::string const & where)
{
	return where.empty() ? s +";" : s + " where " + where +";";
}

void utils::interact(driver::Connection & con)
{
	auto choice = utils::globalMenu();
	while(choice!=5)
	{
		try
		{
			if(choice==1)
			{
				auto result = db_ops::select(con);
				result.print();
				std::cout <<"\n----------\n";
			}
			else
			{
				switch (choice)
				{
					case 2: std::cout << db_ops::insert(con) <<" rows inserted.\n---------\n"; break;
					case 3: std::cout << db_ops::update(con) << " rows updated.\n---------\n"; break;
					case 4: std::cout << db_ops::del(con) << " rows deleted.\n--------\n"; break;
				}
			}
		}
		catch(driver::SQLException & e){ throw e; }
		choice = utils::globalMenu();
	}
}

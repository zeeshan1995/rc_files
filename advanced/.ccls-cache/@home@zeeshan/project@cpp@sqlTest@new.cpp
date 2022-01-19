

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <map>
#include <utility>


#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

std::vector<std::pair<std::string, std::string>> getColNames(sql::Connection * con, const std::string & tableName)
{
	auto stmt =con->createStatement();

	auto meta = (stmt->executeQuery("select * from " + tableName + " limit 1"))->getMetaData();

	auto cols = meta->getColumnCount();

	std::vector<std::pair<std::string,std::string>>colNames;

	for(auto i=1;i<=cols; i++)
		colNames.push_back({meta->getColumnName(i),meta->getColumnTypeName(i)});
	return colNames;
}

std::map<int, sql::PreparedStatement*> getSelectPrepStmt(sql::Connection * con, const std::string & table)
{
	auto colNames = getColNames(con, table);
	std::map<int, sql::PreparedStatement*> prep_stmt;
	for(auto i=0;i<colNames.size(); i++)
		prep_stmt[i+1] = con->prepareStatement("Select * from " + table + " where " + colNames[i].first +"=?");
	return prep_stmt;
}

#if 0
void getChoice(const std::vector<std::pair<std::string, std::string> & colNames)
{

}
#endif

void printQueryResult(sql::ResultSet * r)
{
	auto meta = r->getMetaData();
	auto cols = meta->getColumnCount();
	for(int i=1; i<=cols; i++)
		std::cout << meta->getColumnName(i) <<"\t\t";
	std::cout << "\n";

	while(r->next())
	{
		for(int i=1; i<=cols; i++)
			std::cout << r->getString(i)<<"\t\t";
		std::cout << "\n";
	}
	std::cout << "\n==========\n";

}

int main()
{
	try{
		auto driver = get_driver_instance();
		auto con = driver->connect("localhost", "gemini", "gemini");
		con->setSchema("football");

		auto prep_stmt = getSelectPrepStmt(con, "game");
		auto colNames = getColNames(con, "game");
#if 1
		while(true)
		{
			//		std::cout << "\033[1;31m";//bold red text\033[0m\n";

			int choice;
			std::cout << "Select the column name for projection on the table or else 0 to quit:\n";
			for(auto i=0; i<colNames.size(); i++)
				std::cout << i+1 << "::" << colNames[i].first << "\n";

			//		std::cout << "\033[0m\n";
			std::cin >> choice;
			if(!choice)
				break;
			if(choice > colNames.size())
			{
				std::cout << "Invalid Choice.\n";
				continue;
			}
			std::cout << "Enter value: ";

			if(colNames[choice-1].second=="INT")
			{
				int val;
				std::cin >> val;
				prep_stmt[choice]->setInt(1,val);
			}
			else
			{
				std::string val;
				std::cin >> val;
				prep_stmt[choice]->setString(1,val);
			}
			printQueryResult(prep_stmt[choice]->executeQuery());
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
#endif
}

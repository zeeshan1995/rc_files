

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
/*
void printResult(const sql::ResultSet* result)
{
	while(result->next())
	{
		std::cout << "id: " << result->getString("id") <<"\n mdate: " <<
			result->getString("mdate") << "\n--------\n";
	}
}
*/
int main()
{
	sql::Driver * driver;
	sql::Connection * con;
	sql:: Statement * stmt;
	sql::ResultSet * result;

	driver = get_driver_instance();
	con = driver->connect("localhost", "gemini", "gemini");
	con->setSchema("football");

	if(con->isValid())
		std::cout << "Connected to DB\n";

	stmt = con->createStatement();
	result = stmt->executeQuery("select * from game");

	while(result->next())
	{
		std::cout << "id: " << result->getString("id") <<"\n mdate: " <<
			result->getString("mdate") << "\n--------\n";
	}
	std::cout << "\n==========\n";

	sql::PreparedStatement * prep_stmt;
	prep_stmt = con->prepareStatement("select * from game where team1=?");

	prep_stmt->setString(1,"GRE");
	result = prep_stmt->executeQuery();
	while(result->next())
	{
		std::cout << "id: " << result->getString("id") <<"\n mdate: " <<
			result->getString("mdate") << "\n--------\n";
	}
	std::cout << "\n==========\n";


	delete result;
	delete prep_stmt;
	delete stmt;
	delete con;
}

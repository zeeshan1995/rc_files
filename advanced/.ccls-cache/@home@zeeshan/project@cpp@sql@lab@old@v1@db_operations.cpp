
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

#include "db_operations.hpp"
#include "utility.hpp"

sql::ResultSet * select(sql::Connection * con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"SELECT <columnName(s)> from <tableName> where <condition>;\n";
	
	std::string table = takeInput("tableName: ","person");
	std::string cols = takeInput("columnName(s): ","*");
	std::string where = takeInput("condition: ");

	auto stmt = con->createStatement();
	auto queryStmt=appendWhere("SELECT " + cols + " FROM " + table, where);

	try
	{
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt->executeQuery(queryStmt);
	}
	catch(sql::SQLException & e)
	{
		throw e;
	}
}

manipulationResult insert(sql::Connection * con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"INSERT INTO <tableName>(<colName(s)>) VALUES <value(s)>;\n";
	std::string table = takeInput("tableName: ","person");
	std::string cols = takeInput("colName(s): ");
	std::string values =takeInput("value(s): ");

	try
	{
		auto stmt=con->createStatement();
		auto queryStmt = "INSERT INTO " + table + "(" + cols + ") VALUES(" + values +");";
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		auto result = stmt->execute(queryStmt);
		return {true, "Insertion successfull."};
	}
	catch(sql::SQLException &e)
	{
		throw e;
	}
}

manipulationResult update(sql::Connection * con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"UPDATE <tableName> SET <setCaluse> where <condition>;\n";
	std::string table = takeInput("tableName: ","person");
	std::string setClause = takeInput("setClause: ");
	std::string where = takeInput("condition: ");
	
	if(setClause.empty())
		return {true , "0 rows updated."};

	auto queryStmt=appendWhere("UPDATE " + table + " SET " + setClause, where);
	int count=0;
	try
	{
		auto stmt = con->createStatement();
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		count = stmt->executeUpdate(queryStmt);
		return {true , std::to_string(count) + " rows updated."};
	}
	catch(sql::SQLException &e)
	{
		throw e;
	}
}

manipulationResult del(sql::Connection * con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"DELETE FROM <tableName> where <condition>;\n";
	std::string table=takeInput("tableName: ","person");
	std::string where = takeInput("condition: ");

	auto queryStmt=appendWhere("DELETE FROM " + table, where);
	int count=0;
	try
	{
		auto stmt = con->createStatement();
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		std::cout <<"Are you sure(y/n): ";
		char c;
		std::cin>> c;
		if(c=='y')
			count = stmt->executeUpdate(queryStmt);
		return {true , std::to_string(count) + " rows deleted."};
	}
	catch(sql::SQLException &e)
	{
		throw e;
	}
}

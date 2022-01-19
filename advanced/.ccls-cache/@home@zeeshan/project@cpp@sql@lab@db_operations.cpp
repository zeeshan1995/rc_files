
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

driver::ResultSet db_ops::select(driver::Connection & con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"SELECT <columnName(s)> from <tableName> where <condition>;\n";
	
	std::string table = utils::takeInput("tableName: ","person");
	std::string cols = utils::takeInput("columnName(s): ","*");
	std::string where = utils::takeInput("condition: ");

	driver::Statement stmt(con);
	auto queryStmt=utils::appendWhere("SELECT " + cols + " FROM " + table, where);

	try
	{
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeQuery(queryStmt);
	}
	catch(driver::SQLException & e)
	{
		throw e;
	}
}

int db_ops::insert(driver::Connection & con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"INSERT INTO <tableName>(<colName(s)>) VALUES <value(s)>;\n";
	std::string table = utils::takeInput("tableName: ","person");
	std::string cols = utils::takeInput("colName(s): ");
	std::string values = utils::takeInput("value(s): ");

	try
	{
		driver::Statement stmt(con);
		auto queryStmt = "INSERT INTO " + table + "(" + cols + ") VALUES(" + values +");";
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeUpdate(queryStmt);
	}
	catch(driver::SQLException &e)
	{
		throw e;
	}
}

int db_ops::update(driver::Connection & con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"UPDATE <tableName> SET <setCaluse> where <condition>;\n";
	std::string table = utils::takeInput("tableName: ","person");
	std::string setClause = utils::takeInput("setClause: ");
	std::string where = utils::takeInput("condition: ");
	
	if(setClause.empty())
		return 0;

	auto queryStmt=utils::appendWhere("UPDATE " + table + " SET " + setClause, where);
	try
	{
		driver::Statement stmt(con);
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeUpdate(queryStmt);
	}
	catch(driver::SQLException &e)
	{
		throw e;
	}
}

int db_ops::del(driver::Connection & con)
{
	std::cout << "Complete the SQL command: ";
	std::cout <<"DELETE FROM <tableName> where <condition>;\n";
	std::string table=utils::takeInput("tableName: ","person");
	std::string where = utils::takeInput("condition: ");

	auto queryStmt=utils::appendWhere("DELETE FROM " + table, where);
	try
	{
		driver::Statement stmt(con);
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		std::cout <<"Are you sure(y/n): ";
		char c;
		std::cin>> c;
		int count=0;
		if(c=='y')
			count = stmt.executeUpdate(queryStmt);
		return count; 
	}
	catch(driver::SQLException &e)
	{
		throw e;
	}
}

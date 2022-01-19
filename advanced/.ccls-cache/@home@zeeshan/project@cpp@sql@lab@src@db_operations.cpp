

// Pre-defined header files.
#include <iostream>
#include <algorithm>

// Self-defined header files.

#include "driver.hpp"
#include "db_operations.hpp"
#include "utility.hpp"

namespace db_ops
{
	driver::ResultSet select(driver::Connection & con, std::string const & def_table)
	{
		std::cout << "Complete the SQL command: ";
		std::cout <<"SELECT <columnName(s)> from <tableName> where <condition>;\n";

		std::string table = utils::takeInput("tableName: ",def_table);
		std::string cols = utils::takeInput("columnName(s): ","*");
		std::string where = utils::takeInput("condition: ");

		driver::Statement stmt(con);
		auto queryStmt=utils::appendWhere("SELECT " + cols + " FROM " + table, where);

		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeQuery(queryStmt);
	}

	int insert(driver::Connection & con, std::string const & def_table)
	{
		std::cout << "Complete the SQL command: ";
		std::cout <<"INSERT INTO <tableName>(<colName(s)>) VALUES <value(s)>;\n";
		std::string table = utils::takeInput("tableName: ",def_table);
		std::string cols = utils::takeInput("colName(s): ");
		std::string values = utils::takeInput("value(s): ");

		driver::Statement stmt(con);
		auto queryStmt = "INSERT INTO " + table + "(" + cols + ") VALUES(" + values +");";
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeUpdate(queryStmt);
	}

	int update(driver::Connection & con, std::string const & def_table)
	{
		std::cout << "Complete the SQL command: ";
		std::cout <<"UPDATE <tableName> SET <setCaluse> where <condition>;\n";
		std::string table = utils::takeInput("tableName: ",def_table);
		std::string setClause = utils::takeInput("setClause: ");
		std::string where = utils::takeInput("condition: ");

		if(setClause.empty())
			return 0;

		auto queryStmt=utils::appendWhere("UPDATE " + table + " SET " + setClause, where);
		driver::Statement stmt(con);
		std::cout << "Executing SQL Command: " << queryStmt <<"\n";
		return stmt.executeUpdate(queryStmt);
	}

	int del(driver::Connection & con,std::string const & def_table)
	{
		std::cout << "Complete the SQL command: ";
		std::cout <<"DELETE FROM <tableName> where <condition>;\n";
		std::string table=utils::takeInput("tableName: ",def_table);
		std::string where = utils::takeInput("condition: ");

		auto queryStmt=utils::appendWhere("DELETE FROM " + table, where);
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
}

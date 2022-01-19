
#pragma once

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


namespace driver
{

	class Connection;
	class Driver
	{
		sql::Driver * _driver;

		public:

			Driver();
			friend class Connection;
	};

	class Statement;
	class Connection
	{
		sql::Connection * _con;

		public:
		Connection();
		Connection(Driver & d, std::string const & host, std::string const & user, std::string const & pass);
		~Connection();
		void setSchema(std::string const & schema);
		friend class Statement;
	};

	class ResultSet
	{
		sql::ResultSet * _result;

		public:
		ResultSet();
		ResultSet(sql::ResultSet * result);
		~ResultSet();
		void print();
	//	friend std::ostream & operator << (std::ostream & out, ResultSet const & r);
	};

	class Statement
	{
		sql::Statement * _stmt;

		public:
		Statement();
		Statement(Connection & con);
		~Statement();
		bool execute(std::string const & query);
		ResultSet executeQuery(std::string const & query);
		int executeUpdate(std::string const & query);
	};
}

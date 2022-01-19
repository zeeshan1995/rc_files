

// Pre-defined header files.
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


#include <string>
#include <exception>

// Self-defined header files.

#include "driver.hpp"
#include "sqlexception.hpp"


#define SQLEXCEPTION(e,context) sqlexception::SQLException(e,__func__,__LINE__,context)

namespace driver
{
	Driver:: Driver() { _driver = get_driver_instance(); }

	//class Connection

	Connection::Connection() : _con(nullptr) {}

	Connection:: Connection(Driver const & d, std::string const & host, 
			std::string const & user, std::string const & pass) 
	{
		_con=nullptr;
		try 
		{ 
			_con = (d._driver)->connect(host, user, pass); 
		}
		catch(sql::SQLException & e)
		{ 
			throw SQLEXCEPTION(e,"while connecting");
		}
	}

	Connection::~Connection() 
	{ 
		if(_con) 
			delete _con;
		_con=nullptr; 
	}

	void Connection::setSchema(std::string const & schema) 
	{ 
		try
		{ 
			_con->setSchema(schema);
		} 
		catch(sql::SQLException &e ) 
		{ 
			throw SQLEXCEPTION(e,"while setting schema to " + schema); 
		}
	}

	// class ResultSet

	ResultSet::ResultSet() : _result(nullptr) {}

	ResultSet::ResultSet(sql::ResultSet * result) : _result(result) {}

	ResultSet::~ResultSet()
	{ 
		if(_result) 
			delete _result;
		_result=nullptr; 
	}

	void ResultSet::print()
	{
		auto const meta = _result->getMetaData();
		auto const cols = meta->getColumnCount();
		for(int i=1; i<=int(cols); i++)
			std::cout << meta->getColumnName(i) <<"\t\t";
		std::cout << "\n";

		while(_result->next())
		{
			for(int i=1; i<=int(cols); i++)
				std::cout << _result->getString(i)<<"\t\t";
			std::cout << "\n";
		}
	}
#if 0
	std::ostream & operator << (std::ostream & out, ResultSet const & r)
	{
		auto const result=r._result;
		auto const meta = result->getMetaData();
		auto cols = meta->getColumnCount();
		for(int i=1; i<=int(cols); i++)
			out << meta->getColumnName(i) <<"\t\t";
		out << "\n";

		while(result->next())
		{
			for(int i=1; i<=int(cols); i++)
				out << result->getString(i)<<"\t\t";
			out << "\n";
		}
		return out;
	}
#endif

	// class Statement 

	Statement::Statement() : _stmt(nullptr) {}

	Statement::Statement(Connection & con) : _stmt((con._con)->createStatement()) {}

	Statement::~Statement() 
	{ 
		if(_stmt) 
			delete _stmt; 
		_stmt=nullptr; 
	}

	bool Statement::execute(std::string const & query) 
	{ 
		try
		{ 
			return _stmt->execute(query); 
		}
		catch(sql::SQLException & e)
		{ 
			throw SQLEXCEPTION(e,"while executing the query: " + query); 
		}
	}

	ResultSet Statement::executeQuery(std::string const & query) 
	{ 
		try
		{ 
			return _stmt->executeQuery(query); 
		}
		catch(sql::SQLException & e)
		{ 
			throw SQLEXCEPTION(e,"while executing the query: " + query); 
		}
	}
	int Statement::executeUpdate(std::string const & query) 
	{ 
		try
		{ 
			return _stmt->executeUpdate(query); 
		}
		catch(sql::SQLException & e)
		{ 
			throw SQLEXCEPTION(e,"while executing the query: " + query); 
		}
	}
}




#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "driver.hpp"

#include <string>
#include <exception>

const char * driver::SQLException::what() const throw() { return e.what(); }
int driver::SQLException::getErrorCode() const { return e.getErrorCode(); }
std::string driver::SQLException::getSQLState() const { return e.getSQLState(); }

driver::Driver:: Driver() { driver = get_driver_instance(); }

//class driver::Connection

driver::Connection::Connection() : con(nullptr) {}

driver::Connection:: Connection(Driver & d, std::string const & host, std::string const & user, std::string const & pass) 
{
	con=nullptr;
	try { con = (d.driver)->connect(host, user, pass); }
	catch(sql::SQLException & e){ throw driver::SQLException(e);}
}

driver::Connection::~Connection() { if(con) delete con; con=nullptr; }

void driver::Connection::setSchema(std::string const & schema) 
{ 
	try{ con->setSchema(schema);} 
	catch(sql::SQLException &e ) { throw driver::SQLException(e); }
}

// class driver::ResultSet

driver::ResultSet::ResultSet() : result(nullptr) {}

driver::ResultSet::ResultSet(sql::ResultSet * result) : result(result) {}

driver::ResultSet::~ResultSet(){ if(result) delete result; result=nullptr; }

void driver::ResultSet::print()
{
	auto meta = result->getMetaData();
	auto cols = meta->getColumnCount();
	for(int i=1; i<=int(cols); i++)
		std::cout << meta->getColumnName(i) <<"\t\t";
	std::cout << "\n";

	while(result->next())
	{
		for(int i=1; i<=int(cols); i++)
			std::cout << result->getString(i)<<"\t\t";
		std::cout << "\n";
	}
}
#if 0
std::ostream & operator << (std::ostream & out, driver::ResultSet const & r)
{
	auto result=r.result;
	auto meta = result->getMetaData();
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

// class driver::Statement 

driver::Statement::Statement() : stmt(nullptr) {}

driver::Statement::Statement(driver::Connection & con) : stmt((con.con)->createStatement()) {}

driver::Statement::~Statement() { if(stmt) delete stmt; stmt=nullptr; }

bool driver::Statement::execute(std::string const & query) 
{ 
	try{ return stmt->execute(query); }
	catch(sql::SQLException & e){ throw SQLException(e); }
}

driver::ResultSet driver::Statement::executeQuery(std::string const & query) 
{ 
	try{ return stmt->executeQuery(query); }
	catch(sql::SQLException & e) { throw driver::SQLException(e); }
}
int driver::Statement::executeUpdate(std::string const & query) 
{ 
	try{ return stmt->executeUpdate(query); }
	catch(sql::SQLException & e) { throw driver::SQLException(e); }
}


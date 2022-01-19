

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

int main()
{
	auto driver = get_driver_instance();
	auto con = std::make_shared<sql::Connection>(driver->connect("localhost", "gemini", "gemini"));
#if 0
	con->setSchema("football");
	auto stmt =con->createStatement();

	auto resultset = stmt->executeQuery("select * from game limit 1"); 
	auto meta = resultset->getMetaData();

	auto cols = meta->getColumnCount();
	std::cout << cols << "\n";

	std::vector<std::pair<std::string,std::string>>colNames;

	std::map<int, sql::PreparedStatement*> prep_stmt;
	for(auto i=1;i<=cols; i++)
	{
		auto colname=meta->getColumnName(i);
		auto coltype=meta->getColumnTypeName(i);
		std::cout << colname << " " << coltype << "\n";
		colNames.push_back({colname,coltype});
		prep_stmt[i] = con->prepareStatement("Select * from game where " + colname +"=?");
	}

	int choice=1;
	while(choice)
	{
		std::cout << "Select the column name for projection on the table or else 0 to quit:\n";
		for(auto i=0; i<colNames.size(); i++)
			std::cout << i+1 << "::" << colNames[i].first << "\n";

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
		auto r = prep_stmt[choice]->executeQuery();
		for(auto x : colNames)
			std::cout << x.first <<"\t\t";
		std::cout << "\n";

		while(r->next())
		{
			for(auto x : colNames)
				std::cout << r->getString(x.first) <<"\t\t";
			std::cout << "\n";
		}
		std::cout << "\n==========\n";
	}
class sqlConnection
{
	sql::Driver * driver;
	sql::Connection * con;
	sql::Statement * stmt;
	sql::PreparedStatement * prep_stmt;
	sql::ResultSet * result;

	public:
	sqlConnection(const std::string & host, const std::string & user, const std::string & pass)
	{
		driver = get_driver_instance();
		con = driver->connect(host, user, pass);
		stmt = nullptr;
		prep_stmt = nullptr;
		result = nullptr;
	}

	~sqlConnection()
	{
		if(result)
			delete result;
		if(prep_stmt)
			delete prep_stmt;
		if(stmt)
			delete stmt;
		if(con)
			delete con;
	}
	void setSchema(const std::string & schema)
	{
		con->setSchema(schema);
	}
};
#endif
}

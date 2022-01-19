

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
#include <cppconn/prepared_statement.h>
#include "db_operations.hpp"
#include "utility.hpp"


int main()
{
	try
	{
		auto driver = get_driver_instance();
		auto con = driver->connect("localhost", "gemini", "gemini");
		con->setSchema("test");

		auto choice = globalMenu();
		while(choice!=5)
		{
			if(choice==1)
			{
				auto result = select(con);
				printQueryResult(result);
			}
			else
			{
				manipulationResult mresult;
				switch (choice)
				{
					case 2: mresult = insert(con);break;
					case 3: mresult = update(con);break;
					case 4: mresult = del(con);break;
				}
				std::cout << mresult.getMsg() << "\n";
			}
			choice = globalMenu();
		}
	}
	catch(sql::SQLException & e)
	{
		std::cout << errorHandler(e) << "\n";
		//std::cout << e.what() << "\n";
	}
}

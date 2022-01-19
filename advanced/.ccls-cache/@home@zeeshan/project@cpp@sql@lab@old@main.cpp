
#include "driver.hpp"
#include "db_operations.hpp"

int main()
{
	try{
		driver::Driver d;
		driver::Connection con(d,"localhost", "gemini", "gemini");
		con.setSchema("test");
	//	driver::Statement stmt(con);
	//	(stmt.executeQuery("SELECT * from person;")).print();
		select(con);
	}
	catch(driver::SQLException const & e){
		std::cout <<"name\n";
		std::cout << e.what() << "\n";
		std::cout << e.getErrorCode() << "\n";
		std::cout << e.getSQLState() << "\n";
	}
}



#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

#include "driver.cpp"
#include "db_operations.hpp"
#include "utility.hpp"


int main()
{
	try
	{
		driver::Driver d; 
		driver::Connection con(d, "localhost", "gemini", "gemini");
		con.setSchema("test");
		utils::interact(con);
	}
	catch(driver::SQLException & e)
	{
		std::cout << utils::errorHandler(e) << "\n";
	}
}

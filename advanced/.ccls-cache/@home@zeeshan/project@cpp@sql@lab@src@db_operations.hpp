

#pragma once

#include "driver.hpp"

namespace db_ops
{
	driver::ResultSet select(driver::Connection & con, std::string const & def_table);

	int insert(driver::Connection & con, std::string const & def_table);

	int update(driver::Connection & con, std::string const & def_table);

	int del(driver::Connection & con, std::string const & def_table);
}

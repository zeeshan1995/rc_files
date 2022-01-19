

#pragma once

#include "driver.hpp"

namespace db_ops
{
	driver::ResultSet select(driver::Connection & con);

	int insert(driver::Connection & con);

	int update(driver::Connection & con);

	int del(driver::Connection & con);
}

#pragma once

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

#include "db_operations.hpp"
#include "utility.hpp"

sql::ResultSet * select(sql::Connection * con);

manipulationResult insert(sql::Connection * con);

manipulationResult update(sql::Connection * con);

manipulationResult del(sql::Connection * con);

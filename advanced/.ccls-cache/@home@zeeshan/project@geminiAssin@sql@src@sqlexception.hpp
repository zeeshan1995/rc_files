
#pragma once

// Pre-defined header files.

#include <string>
#include <exception>
#include <cppconn/exception.h>

namespace sqlexception
{
	class SQLException : public std::exception
	{
		sql::SQLException & _e;
		std::string _func;
		int _line;
		std::string _context;

		public:

		SQLException(sql::SQLException & e,std::string const & func, int line, std::string const & context);
		
		virtual const char * what() const throw();
		
		int getErrorCode() const;
		
		std::string getSQLState() const;
		std::string getContext() const;
	};
}

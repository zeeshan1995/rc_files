
// Pre-defined header files.

#include <string>
#include <cppconn/exception.h>

// Self-defined header files.
#include "sqlexception.hpp"

namespace sqlexception
{


	SQLException::SQLException(sql::SQLException & e,
			std::string const & func, int line, 
			std::string const & context) : 
		_e(e), _func(func), _line(line), _context(context) {} 

	const char * SQLException::what() const throw() 
	{ 
		return (std::string(_e.what()) +"\n" + _context).c_str();
		//return (std::string(_e.what()) + "\n" + 
			//"Exception from " + _func + " in line " + std::to_string(_line) + 
			//"\n" + _context + "\n").c_str();
	}

	int SQLException::getErrorCode() const { return _e.getErrorCode(); }

	std::string SQLException::getSQLState() const { return _e.getSQLState(); }
	
	std::string SQLException::getContext() const { return _context; }
}



#include "bar.hpp"
class Bar
{

	public:
		// Default constructor
		Bar()
		{
			std::cout << "Object Bar [" << this << "] created via default constructor\n";
		}

		// Copy constructor
		Bar(Bar const & rhs)
		{
			std::cout << "Object Bar [" << this << "] created via copy constructor\n";
		}

		// Copy assignment operator
		Bar & operator = (Bar const & rhs)
		{
			std::cout << "Object Bar [" << this << "] created via copy assignment operator\n";
			return *this;
		}

		// Destructor
		~Bar();
		{
			std::cout << "Object Bar [" << this << "] destroyed\n";
		}
		// Move constructor
		Bar(Bar && lhs) 
		{
			std::cout << "Object Bar [" << this << "] move constructed\n";
		}
		// Move assignment operator
		Bar & operator = (Bar && rhs)
		{
			std::cout << "Object Bar [" << this << "] constructed via move assignment\n";
			return *this;
		}
};


Bar::Bar()

Bar::Bar(Bar const & rhs)

Bar & Bar::operator = (Bar const & rhs)

Bar::~Bar()
    
Bar::Bar(Bar && lhs)

Bar & Bar::operator = (Bar && rhs)


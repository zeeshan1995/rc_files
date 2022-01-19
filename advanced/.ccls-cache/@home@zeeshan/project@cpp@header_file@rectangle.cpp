
#include "./rectangle.hpp"

rectangle::rectangle(int l, int b)
{
	this->l = l;
	this ->b = b;
}

rectangle::rectangle(rectangle const & r)
{
	this->l = r.l;
	this->b = r.b;
}

int rectangle::area()
{
	return l*b;
}

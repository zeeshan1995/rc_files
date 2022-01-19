


#include <iostream>
/*
void update(float& i);

void g(double const & d, float r)

{

	update(2.0f); // error : const argument

	update(r); // pass reference to r

	update(d); // error : type conversion required

}

*/

int main()
{
//	double d = 5.25;
//	float r = 100.00;

	int x = 5;
	int & y = x;

	std::cout << x << " " << y << "\n";

	y=10;
	std::cout << x << " " << y << "\n";
	int &z = y;
	std::cout <<z << "\n";
}

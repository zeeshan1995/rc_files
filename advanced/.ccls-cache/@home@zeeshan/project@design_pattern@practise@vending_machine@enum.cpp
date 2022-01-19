

#include <iostream>

enum Days 
{
	Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday
};


int main()
{
	Days today;
	today = Friday;
	std::cout << today << "\n";
}

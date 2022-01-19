

#include <iostream>

class A
{
	public:

	mutable int last;
	A();

	int lastint() const;
	int getint() const ;

	private:
	void set() const;
};

A::A()
{
	last = -1;
}

int A::lastint()const
{
	return last;
}

int A::getint() const
{
	set();
	return last;
}

void A::set() const
{
	last++;
}
int main()
{
	A x;
	std::cout << x.lastint() << "\n";
	std::cout << x.getint() << "\n";
	std::cout << x.lastint() << "\n";
}

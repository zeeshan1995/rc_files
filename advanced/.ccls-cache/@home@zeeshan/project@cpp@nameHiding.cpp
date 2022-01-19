

#include <iostream>
#include <string>
class A
{
	public:
		void talk(){ std::cout << "hello\n";}
		void talk(std::string s){std::cout << s << "\n";}
		void talk(int a){std::cout << a << "\n";}
};

class B : public A
{
	public:
		void talk(){ std::cout << "hello in B\n";}
	//	void talk(std::string s){std::cout << s << "\n";}
	//	void talk(int a){std::cout << a << "\n";};
};

int main()
{
	A a;
	B b;
	a.talk();
	a.talk("zeeshan");
	a.talk(25);
	b.talk();
//	b.talk("zeeshan");
//	b.talk(25);
}

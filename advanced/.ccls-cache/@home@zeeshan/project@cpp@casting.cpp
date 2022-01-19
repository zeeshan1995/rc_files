#include <iostream>
#include <string>

using namespace std;

class Base {
	public:
		int f() const {
			cout << "Base::f()\n";
			return 1;
		}

		int f(string) const { return 1; }
		void g() {}
        void say() { std::cout << "base\n";}
        virtual void v_say() { std::cout << "v_say-> base\n";}
        int n = 100;
};

class Derived1 : public Base {
	public:
		void g() const {}
        void say() { std::cout << "derived1\n";}
        void v_say() { std::cout << "v_say-> derived1\n";}
        int n = 101;
        int m = 200;
};

class Derived2 : public Base {
	public:
		// Redefinition:
		int f() const {
			cout << "Derived2::f()\n";
			return 2;
		}
        void say() { std::cout << "derived2\n";}
        void v_say() { std::cout << "v_say-> derived2\n";}
};

class Derived3 : public Base {
	public:
		// Change return type:
		void f() const { cout << "Derived3::f()\n"; }
        void say() { std::cout << "derived3\n";}
        void v_say() { std::cout << "v_say-> derived3\n";}
};

class Derived4 : public Base {
	public:
		// Change argument list:
		int f(int) const {
			cout << "Derived4::f()\n";
			return 4;
		}
        void say() { std::cout << "derived4\n";}
        void v_say() { std::cout << "v_say-> derived4\n";}
};

int main() {
    //static cast
    {
        Base * p = new Base{};
        p->v_say();
        p->say();
        std::cout << p->n << "\n"; //base is called

        //Not use for downcasting if virtual function is there
        Derived1* d1 = static_cast<Derived1*>(p);
        d1->v_say(); // base is called because the dynamic type is still base;
        d1->say(); // derived one is called because static type is derived1
        std::cout << d1->n << "\n"; //unitialised/default initialsed is called
        std::cout << d1->m << "\n";

        std::cout << "------------\n";
        //This works as expected, derived ones are called
        p = new Derived1{};
        d1 = static_cast<Derived1*>(p);
        d1->v_say(); 
        d1->say(); 
        std::cout << d1->n << "\n"; 
        std::cout << d1->m << "\n";

        //add const
        Base a = Base{};
        Base & b = a;
        b.n=23;
        const Base & bc = static_cast<const Base&>(b);
        //bc.n = 23;
        
        //compiler error
        //Base & c = static_cast<Base&>(bc);
    }


    //const cast
    {
        std::cout <<"const_cast \n";
        int n = 23;
        const int & p = n;
        int & pp = const_cast<int&>(p);
        pp = 24;
        std::cout << n <<"\n";

        const int m = 23;
        const int & mp = m;
        pp = const_cast<int&>(mp);
        std::cout << pp << "\n";
        pp = 30;
        std::cout << pp << "\n";
        std::cout << m << "\n";
    }


    //dyamic cast
    {
        std::cout << "-------\n";
        std::cout << "Dynamic cast \n";
        Base * p = new Base{};
        p->v_say();
        p->say();
        std::cout << p->n << "\n"; //base is called

        //Not use for downcasting if virtual function is there
        Derived1* d1 = dynamic_cast<Derived1*>(p);
        if(d1)
        {
            d1->v_say(); // base is called because the dynamic type is still base;
            d1->say(); // derived one is called because static type is derived1
            std::cout << d1->n << "\n"; //unitialised/default initialsed is called
            std::cout << d1->m << "\n";
        }
        else
            std::cout << "Downcast failed\n";

        std::cout << "------------\n";
        //This works as expected, derived ones are called
        p = new Derived1{};
        d1 = static_cast<Derived1*>(p);
        d1->v_say(); 
        d1->say(); 
        std::cout << d1->n << "\n"; 
        std::cout << d1->m << "\n";

        //add const
        Base a = Base{};
        Base & b = a;
        b.n=23;
        const Base & bc = static_cast<const Base&>(b);
        //bc.n = 23;
        
        //compiler error
        //Base & c = static_cast<Base&>(bc);

    }
    //
} ///:~

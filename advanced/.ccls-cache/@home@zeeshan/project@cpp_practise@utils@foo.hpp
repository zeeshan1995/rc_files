
#include <iostream>

struct foo
{
    foo()
    {
        std::cout << "Object foo{tgt[" << this << "]} created via default constructor\n";
//        std::cout << "Resource acquired\n";
    }

	foo(int a)
	{
		
        std::cout << "Object foo{tgt[" << this << "]} created via parametarized constructor foo (int)\n";
	}
    foo(foo const & rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via copy constructor\n";
  //      std::cout << "Resource acquired\n";
    }
    
    foo & operator = (foo const & rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via copy assignment\n";
    //    std::cout << "Resource acquired\n";
        return *this;
    }
    
    ~foo()
    {
        std::cout << "Object foo [" << this << "] destroyed\n";
      //  std::cout << "Resource released\n";
    }
        
    foo(foo && rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via move constructor\n";
    }
    
    foo & operator = (foo && rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via move assignment\n";
        return *this;
    }

	foo (bool a)
	{
        std::cout << "Object foo{tgt[" << this << "]} created via parametarized constructor foo (bool)\n";

	}
#ifdef ILIST

	foo(std::initializer_list<long long> args)
	{
		std::cout << "Object foo{tgt[" << this <<  "]} created via initilizer list costructor\n";
	}
#endif
};


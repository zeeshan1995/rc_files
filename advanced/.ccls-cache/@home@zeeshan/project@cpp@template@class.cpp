// nested_class_template1.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  

class X  
{  

   template <class T>  
   struct Y  
   {  
      T m_t;  
      Y(T t): m_t(t) { }     
   };  

   Y<int> yInt;  
   Y<char> yChar;  

public:  
   X(int i, char c) : yInt(i), yChar(c) { }  
   void print()  
   {  
      cout << yInt.m_t << " " << yChar.m_t << endl;  
   }  
};  

int main()  
{  
   X x(1, 'a');  
   x.print();  
}

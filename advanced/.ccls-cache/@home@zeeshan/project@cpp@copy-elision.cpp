
#include <iostream>

struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
  C operator=(C const & a){ std::cout << "Assingment operator"; return *this;}
};

C f() {
  return C();
}

int main() {
  std::cout << "Hello World!\n";
  C obj = f();
  std::cout << "name\n";
 C x = obj;
  std::cout << "here\n";
  x = obj;
}

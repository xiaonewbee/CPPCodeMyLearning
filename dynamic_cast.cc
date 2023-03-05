#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>
#include <source_location>
#include <string_view>
class Base {
public:
  virtual ~Base() {}
};

class Derived : public Base {
public:
  void foo() { std::cout << "Derived::foo()" << std::endl; }
};

int main() {
  Base* ptr1 = new Derived();
  Derived* ptr2 = dynamic_cast<Derived*>(ptr1);
  if (ptr2 != nullptr) {
    ptr2->foo();
  } else {
    std::cout << "dynamic_cast failed" << std::endl;
  }
  delete ptr1;
  return 0;
}

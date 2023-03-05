#include <iostream>

// 一个接受任意参数的函数
template<typename T>
void foo(T& a) {
    std::cout << "foo lvalue: " << a << std::endl;
}
template<typename T>
void foo(T&& a) {
    std::cout << "foo prvalue" << a << std::endl;
}

template<typename T>
auto forward1(T&& value) {
    return std::forward(value);
}
class Person{};
int main() {
    Person p;
    auto u = new Person();
    
    foo(p);
}
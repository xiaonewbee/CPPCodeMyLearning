template <typename T>
class Base {
public:
    void foo() {
        std::cout << "Base::foo() called with " << sizeof(T) << " bytes\n";
    }
};

template <typename T>
class Derived : public Base<T> {
public:
    void bar() {
        std::cout << "Derived::bar() called\n";
    }
};

int main() {
    Derived<int> d1;
    d1.foo(); // 输出 "Base::foo() called with 4 bytes"
    d1.bar(); // 输出 "Derived::bar() called"
    
    Derived<double> d2;
    d2.foo(); // 输出 "Base::foo() called with 8 bytes"
    d2.bar(); // 输出 "Derived::bar() called"
    
    return 0;
}

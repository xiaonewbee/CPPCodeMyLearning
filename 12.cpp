#include<iostream>
template<size_t n>
struct factorial {

    static constexpr int  value = factorial <n-1>::value * n;
};

template<>
struct factorial<0> {

    static constexpr int  value = 1;
};

int main() {


    std:: cout << factorial<5>::value << '\n';
}
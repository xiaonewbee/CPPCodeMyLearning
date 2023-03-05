#include<iostream>
#include<string>

template<typename T, typename T2 = std::void_t<decltype(&T::f) >>
void t(const T& t) {
    std::cout << "&T::f\n";
}

template<class... _Types>
using void_t = void;




#include<type_traits>

template<class... _Types>
using void_t = void;

template <typename T, typename = void>
struct has_member : std::false_type {};

template <typename T>
struct has_member<T, void_t<decltype(T::member)>> : std::true_type {};


template <typename T>requires requires (T t) {t.f(); T{}; }
// 前面约束子句，后面约束表达式

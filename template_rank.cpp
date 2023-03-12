#include<type_traits>

#include<iostream>
using namespace std;
template <typename T>
struct rank : public integral_constant<size_t, 0> {};

template <typename T>
struct rank<T[]> : public integral_constant<size_t, rank<T>::value + 1> {};

template <typename T, size_t N>
struct rank<T[N]> : public integral_constant<size_t, rank<T>::value + 1> {};

template <typename T>
constexpr auto rank_v = rank<T>::value;


int main() {

    std::string b {"adasd"};

}

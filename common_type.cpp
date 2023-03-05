#include <iostream>
#include <type_traits>

template <typename T, typename U>
void print_common_type(T&& t, U&& u) {
    using CT = std::common_type_t<T, U>;
    std::cout << "Common type of " << typeid(T).name() << " and " << typeid(U).name()
              << " is " << typeid(CT).name() << std::endl;
}

int main() {
    print_common_type(1, 2.0); // Common type of i and d is d
    print_common_type(3, 3L);  // Common type of i and l is l
    print_common_type(4U, -1); // Common type of j and i is unsigned int
    return 0;
}

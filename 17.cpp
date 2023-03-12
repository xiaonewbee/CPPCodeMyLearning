#include <iostream>
#include <vector>
#include <algorithm>
// 第二层元函数
template<typename T>
struct is_pointer {
    static constexpr bool value = false;
};

template<typename T>
struct is_pointer<T*> {
    static constexpr bool value = true;
};

// 第一层元函数
template<typename T>
struct is {
    template<typename U>
    struct type {
        static constexpr bool value = std::is_same_v<T, U>;
    };
    template<int N>
    struct size {
        static constexpr bool value = (sizeof(T) == N);
    };
    using pointer = is_pointer<T>;
};



int main() {
// 示例用法
static_assert(is<int>::type<int>::value, "is<int>::type<int> should be true");
static_assert(!is<int>::type<double>::value, "is<int>::type<double> should be false");
static_assert(is<int>::size<4>::value, "int size is not 4 bytes");
static_assert(!is<int>::size<8>::value, "int size is not 8 bytes");
static_assert(is<int*>::pointer::value, "int* should be a pointer type");
static_assert(!is<int>::pointer::value, "int should not be a pointer type");
  return 0;
}

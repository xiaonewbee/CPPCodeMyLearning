#include <iostream>
#include <type_traits>

struct A { double x; };
const A* a;

decltype(a->x) y;
decltype((a->x)) z = y;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t+u) {
    return t + u;
}

const int& getRef(const int* p) { return *p; };
static_assert(std::is_same_v<decltype(getRef), const int&(const int*)>);

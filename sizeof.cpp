
#include <iostream>
#include <tuple>

template <typename... Args>
struct my_class {
    std::tuple<Args...> args;

    static constexpr std::size_t size = (sizeof(Args) + ... );
};


int main() {
    my_class<int, double, char> c;
    std::cout << c.size << '\n'; // 输出 13
}

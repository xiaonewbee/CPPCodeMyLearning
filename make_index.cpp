#include <iostream>
#include <utility>



template<typename... Args>
void call_foo(const std::tuple<Args...>& args) {
    std::cout << std::get<sizeof...(args)>(args)...;
}

template <typename... Args>
struct my_class {
    std::tuple<Args...> args;

    static constexpr std::size_t size = (sizeof(Args) + ... + 0);
};


template<typename... Args>
void test()
sizeof...(args) std::tuple
int main()
{
    std::tuple<int, double, std::string> args{42, 3.14, "hello"};
    call_foo(args);
    return 0;
}

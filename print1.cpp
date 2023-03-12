// 1: A foo() that accepts arguments that are derived from Base
template <typename T, typename Enable = enable_if_t<std::is_base_of_v<Base, T>>>
void foo(T thing) {
    std::cout << "It's a derived!" << std::endl;
}

// 2: A foo() that accepts all other arguments
template <typename T, typename Enable = enable_if_t<!std::is_base_of_v<Base, T>>>
void foo(T thing) {
    std::cout << "It's not a derived." << std::endl;
}

给无法从函数参数中推导出的模板实参添加默认模板实参以完成自动推导，这样便不必在调用时写明模板实参。
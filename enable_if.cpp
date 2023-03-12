/*
enable_if便是利用了这样子的一个特性， 通过对第二模板参数的默认值设置为void，在模板展开时，
若编译期检测到B为false时，无论你有没有给定T且无论T是什么，编译期都会选择默认分支来进行代
码的生成。此时enable_if就是一个
dummy struct(哑类)，也是我们模板元编程中一个特殊值，unused的定义。
*/
struct unused
{
}; // unused的定义

template <bool B, typename T = void>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;
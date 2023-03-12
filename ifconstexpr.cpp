/*
这里也用到了我们熟悉的模板特化，
但不同的是，这里使用模板特化构成
的分支，来实现了一个编译期的if语
句。如果模板值为false，value则会
特化为0；如果模板值为true，函数模板便
会使用一般的版本，即value为1。同样，在Cpp1
7给我们带来了if constexpr的便利下，我们现在可以
写一个这样的函数，它会在编译期判断需要的分支，舍弃掉不需要的分支，然后相对应的代码。
*/
template <bool B>
struct TmpIf
{
    constexpr static size_t value = 1;
};

template <>
struct TmpIf<false>
{
    constexpr static size_t value = 0;
};

template <bool b>
int TmpIf()
{
    if constexpr (b)
        return 1;
    else
        return 0;
};
// enable_if便是利用了这样子的一个特性，
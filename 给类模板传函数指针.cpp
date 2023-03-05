#include<iostream>
template <typename T, typename F>
class MyClass
{
public:
    MyClass(T &data, const F& f) : m_data(data), f_(f) {}

    void do_something()
    {
        // 使用 FuncPtr 指向的函数来操作 m_data
        FuncPtr(m_data);
    }

private:
    T &m_data;
    const F& f_;
};

// 函数指针类型为 void (*)(int&)
void increment(int &x)
{
    ++x;
}

int main()
{
    int num = 10;
    MyClass obj(num,increment);
    obj.do_something();            // 调用 increment 函数，num 的值将被增加
    std::cout << num << std::endl; // 输出 11
    return 0;
}

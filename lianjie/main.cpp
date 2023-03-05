#include "myfirst.hpp"
// use of the template
int main()
{
double ice = 3.0;
printTypeof(ice); // call function template for type double
}

/*
编译器很可能会正常编译这个程序， 但是链接器则可能会报错说： 找不到函数 printTypeof()
的定义。
出现这一错误的原因是函数模板 printTypeof()的定义没有被实例化。 为了实例化一个模板，
编译器既需要知道需要实例化哪个函数， 也需要知道应该用哪些模板参数来进行实例化。 不
幸的是， 在上面这个例子中， 这两组信息都是被放在别的文件里单独进行编译的。 因此当编
译器遇到对 printTypeof()的调用时， 却找不到相对应的函数模板定义来针对 double 类型进行
实例化， 这样编译器只能假设这个函数被定义在别的地方， 然后创建一个指向那个函数的引
用（会在链接阶段由链接器进行解析） 。 另一方面， 在编译器处理 myfirst.cpp 的时候， 却没
有任何指示让它用某种类型实例化模板。
*/
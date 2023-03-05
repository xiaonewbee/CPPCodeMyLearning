#include <iostream>
#include <ranges>
#include <vector>

#include <ranges>
#include <iostream>
#include<typeinfo>

void compare(int l, int r) {

}

template<typename F>
void trans(F&& f) {

}

template<>  // void trans(F&& f)
void trans<void (&)(int, int)>(void (&f)(int, int))
{
}
template<>// void trans(F& f)
void trans<void (int, int)>(void (&f)(int, int))
{
}
template<>// void trans(F f)  这个是退化
void trans<void (*)(int, int)>(void (*f)(int, int))
{
}
int main()
{


    typeid(1).name();
    trans(compare);

    return 0;
   
}
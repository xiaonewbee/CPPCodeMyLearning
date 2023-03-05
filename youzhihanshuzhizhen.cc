#include<iostream>
#include<algorithm>
#include<vector>
template<typename T, typename F>
void func(T l, T r, F&& f) {
    for (auto i {l}; i != r; i++) {
        f();
        std::cout << ' ';
    }
        f();

}

void foo() {
    std::cout<<'1' ;
}

int main() {


    std::vector<int> vec = {1, 2, 3};
    func(vec.begin(), vec.end(), foo);




}
#include <iostream>
// #include <bit>
using namespace std;


void operator""_r(const char* str, size_t size) {
    cout << str << size <<'\n';
}
int main() {
    "123456"_r;
    auto str = "**"s;
    // for (auto i = 1; i<64;i++){
    //     cout << i << ' ' << bit_floor(i) <<' ' << bit_ceil(i) << '\n';

    // }
    cout << __cplusplus;
}

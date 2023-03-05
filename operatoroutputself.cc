#include <iostream>
#include <source_location>
#include <string>
#include <ranges>





// 
// main.cpp:12 message.

enum class LogLevel
{
    info = 0,
    error
};
// 抽象->
//class LogFormatter; // 输出的格式
//class LogAppender; // 输出的地方
class MyLogger
{
    public:
    MyLogger(const std::source_location& localtion 
    = std::source_location::current()):loc(localtion)
    {}
    void print_location() {
        std::cout << "File: " << loc.file_name() << ", Line: " << loc.line() << ", Function: " << loc.function_name() << ", Column: " << loc.column() << '\n';
    }
    ~MyLogger(){
        print_location();
    }
private:
    const std::source_location& loc;
};


int main() {

    MyLogger();
    return 0;
}
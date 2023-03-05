#include <iostream>
#include <source_location>
#include <string>
#include <format>
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
    MyLogger(LogLevel level, const std::source_location& localtion = std::source_location::current()):
        _localtion(localtion),
        _level(level)
    { }
    // 析构的时候进行日志输出
    ~MyLogger()
    {
        std::cout << format() << std::endl;
    }

    const MyLogger& operator<<(const std::string& message) const
    {
        _message += message;
        return *this;
    }
private:
    std::string format()
    {

        std::string strLevel = "unknown";
        if (LogLevel::info == _level) {
            strLevel = "Info";
        }
        else if (LogLevel::error == _level) {
            strLevel = "Error";
        }
        return std::format("{} {}:{} {}", static_cast<int>(_level), _localtion.file_name(), _localtion.line(), _message);
    }
private:
    const std::source_location& _localtion;
    mutable std::string _message;
    LogLevel _level;
};

int main()
{
    {
        MyLogger(LogLevel::info) << "log message";
        // 延长生命周期
        const auto& logger = MyLogger(LogLevel::error);
        // 继续写入上一个日志
        for (auto i : std::views::iota(1, 10)) {

            logger << std::to_string(i) << " ";
        }

    }
    return 0;
}
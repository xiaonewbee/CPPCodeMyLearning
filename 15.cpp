#include <iostream>
#include <source_location>
#include <string>
#include <format>
#include <ranges>

enum class LogLevel
{
    info = 0,
    error
};

class MyLogger
{
public:
    MyLogger(LogLevel level, 
    const std::source_location& localtion
     = std::source_location::current()
     ):
        _localtion(localtion),
        _level(level)
    { }
    ~MyLogger() {
        std::cout<<format() << std::endl;
    }
    const MyLogger& operator<<(const std::string& message)const{
        _message += message;
        return *this;
    }
private:
    std::string format() {
        std::string strLevel
    }
    const std::source_location& _localtion;
    mutable std::string _message;
    LogLevel _level;
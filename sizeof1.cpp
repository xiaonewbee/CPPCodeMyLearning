#include <iostream>

// 递归终止函数
void printArgs() {
    std::cout << std::endl;
}

// 变参模板函数
template<typename T, typename... Args>
void printArgs(const T& t, const Args&... args) {
    std::cout << t << " ";
    printArgs(args...);
}

// 统计模板参数个数
template<typename... Args>
void countArgs(const Args&... args) {
    std::cout << "Number of arguments: " << sizeof...(args) << std::endl;
}

int main() {
    int a = 1;
    double b = 2.0;
    std::string c = "Hello";
    char d = '!';
    printArgs(a, b, c, d);  // 输出: 1 2 Hello !
    countArgs(a, b, c, d);  // 输出: Number of arguments: 4
    return 0;
}


#include <iostream>

// 递归终止函数
void printArgs()
{
  std::cout.operator<<(std::endl);
}


// 变参模板函数
template<typename T, typename ... Args>
void printArgs(const T & t, const Args &... args)
{
  (std::cout << t) << " ";
  printArgs(args... );
}


/* First instantiated from: insights.cpp:26 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void printArgs<int, double, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(const int & t, const double & __args1, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > & __args2, const char & __args3)
{
  std::operator<<(std::cout.operator<<(t), " ");
  printArgs(__args1, __args2, __args3);
}
#endif


/* First instantiated from: insights.cpp:12 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void printArgs<double, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(const double & t, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > & __args1, const char & __args2)
{
  std::operator<<(std::cout.operator<<(t), " ");
  printArgs(__args1, __args2);
}
#endif


/* First instantiated from: insights.cpp:12 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void printArgs<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(const std::basic_string<char, std::char_traits<char>, std::allocator<char> > & t, const char & __args1)
{
  std::operator<<(std::operator<<(std::cout, t), " ");
  printArgs(__args1);
}
#endif


/* First instantiated from: insights.cpp:12 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void printArgs<char>(const char & t)
{
  std::operator<<(std::operator<<(std::cout, t), " ");
  printArgs();
}
#endif


// 统计模板参数个数
template<typename ... Args>
void countArgs(const Args &... args)
{
  std::operator<<(std::cout, "Number of arguments: ").operator<<(sizeof...(args)).operator<<(std::endl);
}


/* First instantiated from: insights.cpp:27 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void countArgs<int, double, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, char>(const int & __args0, const double & __args1, const std::basic_string<char, std::char_traits<char>, std::allocator<char> > & __args2, const char & __args3)
{
  std::operator<<(std::cout, "Number of arguments: ").operator<<(4).operator<<(std::endl);
}
#endif


int main()
{
  int a = 1;
  double b = 2.0;
  std::basic_string<char, std::char_traits<char>, std::allocator<char> > c = std::basic_string<char, std::char_traits<char>, std::allocator<char> >("Hello", std::allocator<char>());
  char d = '!';
  printArgs(a, b, c, d);
  countArgs(a, b, c, d);
  return 0;
}


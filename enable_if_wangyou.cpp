#include <iostream>
#include <tuple>
using namespace std;

// print_tp
template <size_t I = 0, typename Tuple>
typename enable_if<I == tuple_size<Tuple>::value>::type
print_tp(Tuple t)
{
}

template <size_t I = 0, typename Tuple>
    typename enable_if < I<tuple_size<Tuple>::value>::type
                         print_tp(Tuple t)
{
    cout << get<I>(t) << endl;
    print_tp<I + 1>(t);
}
template <typename... Args>
void print(Args... args)
{
    print_tp(make_tuple(args...));
}
int main()
{
    print(1, 2, 3, 4);
    return 0;
}




#include <iostream>
#include <tuple>
using namespace std;

// print_tp
template<size_t I = 0, typename Tuple>
typename enable_if<I == tuple_size<Tuple>::value>::type print_tp(Tuple t)
{
}


/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename enable_if<4UL == tuple_size<tuple<int, int, int, int> >::value>::type print_tp<4, std::tuple<int, int, int, int> >(std::tuple<int, int, int, int> t)
{
}
#endif


template<size_t I = 0, typename Tuple>
typename enable_if<I < tuple_size<Tuple>::value>::type print_tp(Tuple t)
{
  operator<<(operator<<(std::cout, get<I>(t)), endl);
  print_tp<I + 1>(t);
}


/* First instantiated from: insights.cpp:22 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename enable_if<0UL < tuple_size<tuple<int, int, int, int> >::value>::type print_tp<0, std::tuple<int, int, int, int> >(std::tuple<int, int, int, int> t)
{
  std::cout.operator<<(std::get<0UL>(t)).operator<<(std::endl);
  print_tp<0UL + 1>(std::tuple<int, int, int, int>(t));
}
#endif


/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename enable_if<1UL < tuple_size<tuple<int, int, int, int> >::value>::type print_tp<1, std::tuple<int, int, int, int> >(std::tuple<int, int, int, int> t)
{
  std::cout.operator<<(std::get<1UL>(t)).operator<<(std::endl);
  print_tp<1UL + 1>(std::tuple<int, int, int, int>(t));
}
#endif


/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename enable_if<2UL < tuple_size<tuple<int, int, int, int> >::value>::type print_tp<2, std::tuple<int, int, int, int> >(std::tuple<int, int, int, int> t)
{
  std::cout.operator<<(std::get<2UL>(t)).operator<<(std::endl);
  print_tp<2UL + 1>(std::tuple<int, int, int, int>(t));
}
#endif


/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
typename enable_if<3UL < tuple_size<   tuple<int, int, int, int>   >::value   >::type print_tp<3, std::tuple<int, int, int, int> >(std::tuple<int, int, int, int> t)
{
  std::cout.operator<<(std::get<3UL>(t)).operator<<(std::endl);
  print_tp<3UL + 1>(std::tuple<int, int, int, int>(t));
}
#endif

template<typename ... Args>
void print(Args... args)
{
  print_tp(make_tuple(args... ));
}


/* First instantiated from: insights.cpp:26 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void print<int, int, int, int>(int __args0, int __args1, int __args2, int __args3)
{
  print_tp(std::make_tuple(__args0, __args1, __args2, __args3));
}
#endif

int main()
{
  print(1, 2, 3, 4);
  return 0;
}

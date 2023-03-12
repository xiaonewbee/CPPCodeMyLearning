typedef char yes_type;
struct no_type { char pad[8]; };

template <typename From, typename To, bool = (is_void<From>::value || is_function<To>::value || is_array<To>::value)>
struct is_convertible_impl // Anything is convertible to void, nothing is convertible to function or array
{ static const bool value = is_void<To>::value; };

template <typename From, typename To>
class is_convertible_impl<From, To, false>
{
    template <typename To1>
    static void ToFunction(To1 arg); // for example, To1 is class A, we try to call ToFunction(A arg), arg is B, it will try cast B to A

    template <typename From1, typename To1>
    static decltype(ToFunction<To1>(declval<From1>()), yes_type()) is(int); // implicitly cast From1 to To1

    template <typename, typename>
    static no_type is(...); // sizeof(no_type) == 8
public:
    static const bool value = sizeof(is<From, To>(0)) == 1; // if its return type is yes_type
};

template <typename From, typename To>
struct is_convertible : integral_constant<bool, is_convertible_impl<From, To>::value> {};

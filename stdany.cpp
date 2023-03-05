template<class T>
class type_is{
    using type = T;
};

template<>
struct tuple_element<0, User> : type_is<int> {};

template<>
struct tuple_element<1, User> : type_is<std::string> {};
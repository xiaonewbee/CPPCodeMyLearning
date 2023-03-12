template< class T, class Alloc, class U >
constexpr typename std::vector<T, Alloc>::size_type
    erase( std::vector<T, Alloc>& c, const U& value );


auto it = std::remove(c.begin(), c.end(), value);
auto r = std::distance(it, c.end());
c.erase(it, c.end());
return r;

// std::erase_if is another C++ STL algorithm that was added in C++20, and it is similar to std::erase. The difference is that std::erase_if takes a predicate pred that specifies a condition for elements to be removed, rather than a specific value.

// std::erase_if() 函数的实际调用为 container.erase(std::remove_if(container.begin(), container.end(), predicate), container.end())，相当于在调用 std::remove_if() 后再调用一次容器的 erase() 函数。
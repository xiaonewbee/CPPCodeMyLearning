#include <vector>
#include <ranges>
#include <iostream>

namespace views
{
    template <typename T, typename F>
    class filter
    {
        private:
        F& f;
        public:
        filter(const F f) : _f(f) {}

        const vector<int> &operator()(const std::vector<int> &data)
        {
            std::vector<int> new_vec;
            for (const auto &i : data)
            {
                if (even(i))
                {
                    new_vec.emplace_back(i);
                }
            }
            return new_vec;
        }
    };
}

template <typename T, typename F>
std::vector<int> operator|(std::vector<T> &vec, F &&f)
{

    return f(vec);
}

int main()
{

    std::vector<int> data = {1, 3, 4, 5, 6};
    std::vector<int> v1 = {2, 3, 4, 5};

    auto even = [](int i)
    { return 0 == i % 2; };
    auto square = [](int i)
    { return i * i; };
    const auto ret = data | [even](const std::vector<int> &data)
    {
        std::vector<int> new_vec;
        for (const auto &i : data)
        {
            if (even(i))
            {
                new_vec.emplace_back(i);
            }
        }
        return new_vec;
    };
    for (auto i : ret)
    {
        std::cout << i << ' ';
    }

    // for(int i : v | std::ranges::view::filter(even) | std::view::transform(square)) {
    //     std::cout << i << ' ';
    // }
}
#include <array>
#include <iostream>

int main()
{
    std::array data{ 0, 1, 2, 3, 4, 5, 6 };

    auto begin{ &data[0] };
    // note that this points to one spot beyond the last element
    auto end{ begin + std::size(data) };

    // for-loop with pointer
    for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
    {
        std::cout << *ptr << ' '; // Indirection to get value of current element
    }
    std::cout << '\n';

    {
        std::array array{ 1, 2, 3 };
        // Ask our array for the begin and end points (via the begin and end member functions).
        auto begin{ array.begin() };
        auto end{ array.end() };
        for (auto p{ begin }; p != end; ++p) // ++ to move to next element.
        {
            std::cout << *p << ' '; // Indirection to get value of current element.
        }
        std::cout << '\n';
    }

    {
        std::array array{ 1, 2, 3 };
        // Use std::begin and std::end to get the begin and end points.
        auto begin{ std::begin(array) };
        auto end{ std::end(array) };
        for (auto p{ begin }; p != end; ++p) // ++ to move to next element
        {
            std::cout << *p << ' '; // Indirection to get value of current element
        }
        std::cout << '\n';
    }

    return 0;
}
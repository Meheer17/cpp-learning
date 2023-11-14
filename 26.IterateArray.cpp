#include <iostream>
#include <vector>
#include <string>
#include <ranges> // C++20
#include <string_view>
#include <array>

int main()
{
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (int num : fibonacci) // iterate over array fibonacci and copy each value into `num`
       std::cout << num << ' '; // print the current value of `num`
    std::cout << '\n';

    {
        using namespace std::literals; // for s suffix for std::string literals
        std::vector words{ "peter"s, "likes"s, "frozen"s, "yogurt"s }; // std::vector<std::string>
        for (auto word : words)
            std::cout << word << ' ';
        std::cout << '\n';
    }

    {
        using namespace std::literals;
        std::vector words{ "peter"sv, "likes"sv, "frozen"sv, "yogurt"sv }; // std::vector<std::string_view>
        for (auto word : words) // We normally pass string_view by value, so we'll use auto here
            std::cout << word << ' ';
        std::cout << '\n';
    }

    {
        std::array fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::array here
        for (auto number : fibonacci)
            std::cout << number << ' ';
        std::cout << '\n';
    }

    {
        using namespace std::literals; // for sv suffix for std::string_view literals
        std::vector words{ "Alex"sv, "Bobby"sv, "Chad"sv, "Dave"sv }; // sorted in alphabetical order
        for (const auto& word : std::views::reverse(words)) // create a reverse view
            std::cout << word << ' ';
        std::cout << '\n';
    }
    return 0;
}
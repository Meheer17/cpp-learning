#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include "66.Lamdas.h"

int main()
{
  constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // Define the function right where we use it.
  auto found{ std::find_if(arr.begin(), arr.end(),
                           [](std::string_view str) // here's our lambda, no capture clause
                           {
                              return str.find("nut") != std::string_view::npos;
                           })};

    // Good: Instead, we can store the lambda in a named variable and pass it to the function.
    auto isEven{
      [](int i)
      {
          return (i % 2) == 0;
      }
    };
    std::array<int, 5> array {1,2,3,4,5};
    std::cout << std::all_of(array.begin(), array.end(), isEven);

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}
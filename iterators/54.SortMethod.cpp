#include <iostream>
#include <iterator>
#include <utility>
#include "54.SortMethod.h"

void sort(int* begin, int* end)
{
    for (auto startElement{ begin }; startElement != end-1; ++startElement)
    {
        auto smallestElement{ startElement };
        // std::next returns a pointer to the next element, just like (startElement + 1) would.
        for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
            compare(currentElement, smallestElement);
        std::swap(*startElement, *smallestElement);
    }
}

void compare(int *currentElement, int *&smallestElement)
{
    {
        if (*currentElement < *smallestElement)
        {
            smallestElement = currentElement;
        }
    }
}

int main()
{
    int array[]{ 2, 1, 9, 4, 5 };
    sort(std::begin(array), std::end(array));
    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
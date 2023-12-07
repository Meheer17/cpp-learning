#include <vector>
#include <iostream>

int main()
{
    std::vector v { 0, 1, 2, 3 };
    for (auto num : v) // implicitly iterates over v
    {
        if (num % 2 == 0)
            v.push_back(num + 1); // when this invalidates the iterators of v, undefined behavior will result
    }
    for(int i : v)
        std::cout << i << " "; 
    // Another Example of this, 

    {
        std::vector v{ 1, 2, 3, 4, 5, 6, 7 };
        auto it{ v.begin() };
        ++it; // move to second element
        std::cout << *it << '\n'; // ok: prints 2
        v.erase(it); // erase the element currently being iterated over
        // erase() invalidates iterators to the erased element (and subsequent elements)
        // so iterator "it" is now invalidated
        ++it; // undefined behavior
        std::cout << *it << '\n'; // undefined behavior
    }
    {
        std::vector v{ 1, 2, 3, 4, 5, 6, 7 };
        auto it{ v.begin() };
        ++it; // move to second element
        std::cout << *it << '\n';
        it = v.erase(it); // erase the element currently being iterated over, set `it` to next element
        std::cout << *it << '\n'; // now ok, prints 3
    }
    return 0;
}

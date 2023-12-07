#include <iostream>
#include <vector>


void printLength(const std::vector<int>& v)
{
	std::cout << "The length is: "	<< v.size() << '\n';
}

void printCapLen(const std::vector<int>& v)
{
	std::cout << "Capacity: " << v.capacity() << " Length:"	<< v.size() << '\n';
}

int main()
{
    std::vector v{ 0, 1, 2 }; // create vector with 3 elements
    std::cout << "The length is: " << v.size() << '\n';
    v.resize(5);              // resize to 5 elements
    std::cout << "The length is: " << v.size() << '\n';
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    {
        std::vector v{ 0, 1, 2, 3, 4 }; // length is initially 5
        printLength(v);
        v.resize(3);                    // resize to 3 elements
        printLength(v);
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    {
        // Create a vector with length 5
        std::vector v{ 0, 1, 2, 3, 4 };
        v = { 0, 1, 2, 3, 4 }; // okay, array length = 5
        printCapLen(v);

        for (auto i : v)
            std::cout << i << ' ';
        std::cout << '\n';

        // Resize vector to 3 elements
        v.resize(3); // we could also assign a list of 3 elements here
        printCapLen(v);

        for (auto i : v)
            std::cout << i << ' ';
        std::cout << '\n';

        // Resize vector back to 5 elements
        v.resize(5);
        printCapLen(v);

        for (auto i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    {
        std::vector<int> v(1000); // allocate room for 1000 elements
        printCapLen(v);

        v.resize(0); // resize to 0 elements
        printCapLen(v);

        v.shrink_to_fit();
        printCapLen(v);
    }

    return 0;
}
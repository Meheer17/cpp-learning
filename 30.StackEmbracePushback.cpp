// This example will only compile in C++20 because emplace_back doesn't work with aggregate initialization until C++20
#include <iostream>
#include <string>
#include <vector>

struct Foo
{
	std::string a{};
	int b{};
};

int main()
{
	std::vector<Foo> stack{};

	// When we already have an object, push_back and emplace_back are the same
	Foo f{ "a", 2 };
	stack.push_back(f);
	stack.emplace_back(f);

	// When we need to create a temporary object to push, emplace_back is more efficient
	stack.push_back({ "a", 2 }); // creates a temporary object, and then copies it into the vector
	stack.emplace_back("a", 2);  // forwards the arguments so the object can be created directly in the vector (no copy made)

	// Note: emplace_back() does not work with aggregates prior to C++20

	return 0;
}
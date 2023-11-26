#include <iostream>

void printArray(const int* begin, const int* end)
{
	for (; begin != end; ++begin)   // iterate from begin up to (but excluding) end
	{
		std::cout << *begin << ' '; // dereference our loop variable to get the current element
	}

	std::cout << '\n';
}

int main()
{
    int x {};
    const int* ptr{ &x }; // assume 4 byte ints
    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';
    {
        int x {};
        const int* ptr{ &x }; // assume 4 byte ints
        std::cout << ptr << ' ' << (ptr - 1) << ' ' << (ptr - 2) << '\n';
    }
    
    {
        int x {};
        const int* ptr{ &x }; // assume 4 byte ints
        std::cout << ptr << '\n';
        ++ptr; // ptr = ptr + 1
        std::cout << ptr << '\n';
        --ptr; // ptr = ptr - 1
        std::cout << ptr << '\n';
    }

    {
        const int arr[] { 3, 2, 1 };
        std::cout << "\n" << &arr << "\n";
        // First, let's use subscripting to get the address and values of our array elements
        std::cout << &arr[0] << ' ' << &arr[1] << ' ' << &arr[2] << '\n';
        std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
        // Now let's do the equivalent using pointer arithmetic
        std::cout << arr<< ' ' << (arr+ 1) << ' ' << (arr+ 2) << '\n';
        std::cout << *arr<< ' ' << *(arr+ 1) << ' ' << *(arr+ 2) << '\n';
    }

    {
        constexpr int arr[]{ 9, 7, 5, 3, 1 };
        const int* begin{ arr };                // begin points to start element
        const int* end{ arr + std::size(arr) }; // end points to one-past-the-end element
        printArray(begin, end);
    }

    {
        int arr[] {1,2,3,4,5};
    	for (auto e : arr)         // iterate from `begin` up to (but excluding) `end`
	    {
	    	std::cout << e << ' '; // dereference our loop variable to get the current element
    	}

    }
        
    return 0;
}
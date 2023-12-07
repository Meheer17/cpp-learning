#include <iostream>
#include <limits>

int main()
{
	std::cout << "Hello, world!";
	int x = 5;
	return 0;
}   

// STD ENDL, COUT, CIN

int std_cout()
{
    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console
    std::cout << "My name is Alex." << std::endl;

    return 0;
}

int std_cin()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{ }; // define variable x to hold user input (and zero-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}

int size_of()
{
	std::cout << sizeof(int); // print how many bytes of memory an int value takes
	return 0;
}